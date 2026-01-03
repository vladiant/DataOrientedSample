#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

#include "ComponentsManager.h"
#include "GameObject.h"

constexpr int kLoopCount = 20;

void CacheUnfriendlyMethod(
    std::vector<std::shared_ptr<GameObject>>& vecObjects);

void CacheFriendlyMethod(ComponentsManager& compMgr);

auto main() -> int {
  const int numObjects = 3500000;

  auto compMgr = ComponentsManager(numObjects);
  std::vector<std::shared_ptr<GameObject>> vecObjects;

  for (int i = 0; i < numObjects; i++) {
    vecObjects.push_back(std::make_shared<GameObject>());
    compMgr.CreateComponentsForId(vecObjects.back()->GetId());
  }

  CacheUnfriendlyMethod(vecObjects);
  CacheFriendlyMethod(compMgr);
}

void CacheUnfriendlyMethod(
    std::vector<std::shared_ptr<GameObject>>& vecObjects) {
  // ############## POINTER CHASE/CACHE UNFRIENDLY ##############
  std::cout << "Measuring non cache friendly (pointer chase) mode...\n";

  auto pointerChaseStart = std::chrono::steady_clock::now();

  for (int loops = 0; loops < kLoopCount; loops++)
    for (auto& object : vecObjects) object->Update();

  auto pointerChaseEnd = std::chrono::steady_clock::now();

  std::cout << "Elapsed time in milliseconds POINTER CHASE: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                   pointerChaseEnd - pointerChaseStart)
                   .count()
            << " ms\n";
}

void CacheFriendlyMethod(ComponentsManager& compMgr) {
  // ############## LOCALITY/CACHE FRIENDLY ##############
  std::cout << "Measuring cache friendly (locality) mode...\n";

  auto cacheStart = std::chrono::steady_clock::now();

  for (int loops = 0; loops < kLoopCount; loops++) compMgr.Update();

  auto cacheEnd = std::chrono::steady_clock::now();

  std::cout << "Elapsed time in milliseconds CACHE: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(cacheEnd -
                                                                     cacheStart)
                   .count()
            << " ms\n";
}
