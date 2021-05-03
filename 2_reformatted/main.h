#pragma once

#include <vector>

class GameObject;
class ComponentsManager;

void CacheUnfriendlyMethod(std::vector<GameObject*>& vecObjects);

void CacheFriendlyMethod(ComponentsManager& compMgr);
