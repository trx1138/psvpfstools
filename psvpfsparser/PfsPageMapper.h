#pragma once

#include <cstdint>

#include <memory>
#include <map>

#include <boost/filesystem.hpp>

#include "IF00DKeyEncryptor.h"
#include "ICryptoOperations.h"

#include "Utils.h"

struct sce_ng_pfs_header_t;
class sce_idb_base_t;
struct sce_ng_pfs_file_t;
struct sce_ng_pfs_dir_t;

class PfsPageMapper
{

public:
   int bruteforce_map(std::shared_ptr<ICryptoOperations> cryptops, std::shared_ptr<IF00DKeyEncryptor> iF00D, boost::filesystem::path titleIdPath, const unsigned char* klicensee, const sce_ng_pfs_header_t& ngpfs, std::shared_ptr<sce_idb_base_t> fdb, std::map<std::uint32_t, sce_junction>& pageMap, std::set<sce_junction>& emptyFiles);

   int load_page_map(boost::filesystem::path filepath, std::map<std::uint32_t, std::string>& pageMap);
};