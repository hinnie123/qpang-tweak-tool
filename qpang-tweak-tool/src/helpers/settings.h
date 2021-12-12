#pragma once

#include "json/json.h"

namespace settings {
	void ensureDirExists();
	nlohmann::json fileToJson(std::string fileName);

	void saveAll();
	void loadAll();
}