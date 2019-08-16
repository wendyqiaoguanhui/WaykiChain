// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2017-2019 The WaykiChain Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CONFIG_CONST_H
#define CONFIG_CONST_H

#include <string>
#include <unordered_map>

using namespace std;

namespace SYMB {
    static const string WICC                = "WICC";
    static const string WGRT                = "WGRT";
    static const string WUSD                = "WUSD";
    static const string WCNY                = "WCNY";

    static const string WBTC                = "WBTC";
    static const string WETH                = "WETH";
    static const string WEOS                = "WEOS";

    static const string USD                 = "USD";
    static const string CNY                 = "CNY";
    static const string EUR                 = "EUR";
    static const string BTC                 = "BTC";
    static const string USDT                = "USDT";
    static const string GOLD                = "GOLD";
    static const string KWH                 = "KWH";
}

struct CoinUnitTypeHash {
    size_t operator()(const string &unit) const noexcept {
        return std::hash<string>{}(unit);
    }
};

namespace COIN_UNIT {
    static const string SAWI = "sawi";
    static const string QUWI = "quwi";
    static const string MUWI = "muwi";
    static const string HUWI = "huwi";
    static const string SIWI = "siwi";
    static const string MIWI = "miwi";
    static const string LEWI = "lewi";
    static const string FEWI = "fewi";
    static const string WI   = "wi";
    static const string KWI  = "kwi";
    static const string MWI  = "mwi";
}

static const unordered_map<string, uint64_t, CoinUnitTypeHash> CoinUnitTypeTable {
    {"sawi", 1                  },  // 0.00000001
    {"quwi", 10                 },  // 0.0000001
    {"muwi", 100                },  // 0.000001
    {"huwi", 1000               },  // 0.00001
    {"siwi", 10000              },  // 0.0001
    {"miwi", 100000             },  // 0.001
    {"lewi", 1000000            },  // 0.01
    {"fewi", 10000000           },  // 0.1
    {"wi",   100000000          },  // 1
    {"kwi",  100000000000       },  // 1000
    {"mwi",  100000000000000    },  // 1000,000
};

static const uint64_t COIN = 100000000;  //10^8 = 1 WICC
static const uint64_t CENT = 1000000;    //10^6 = 0.01 WICC

/** the max token symbol len */
static const uint32_t MAX_TOKEN_SYMBOL_LEN = 12;
/** the max asset name len */
static const uint32_t MAX_ASSET_NAME_LEN = 12;
static const uint64_t MAX_ASSET_TOTAL_SUPPLY = 9000000000 * COIN; // 90 billion

/** the total blocks of burn fee need */
static const uint32_t DEFAULT_BURN_BLOCK_SIZE = 50;
static const uint64_t MAX_BLOCK_RUN_STEP      = 12000000;

/** The maximum allowed size for a serialized block, in bytes (network rule) */
static const uint32_t MAX_BLOCK_SIZE = 4000000;
/** Default for -blockmaxsize and -blockminsize, which control the range of sizes the mining code will create **/
static const uint32_t DEFAULT_BLOCK_MAX_SIZE = 3750000;
static const uint32_t DEFAULT_BLOCK_MIN_SIZE = 1024 * 10;
/** Default for -blockprioritysize, maximum space for zero/low-fee transactions **/
static const uint32_t DEFAULT_BLOCK_PRIORITY_SIZE = 50000;
/** The maximum size for transactions we're willing to relay/mine */
static const uint32_t MAX_STANDARD_TX_SIZE = 100000;

/** The maximum number of orphan blocks kept in memory */
static const uint32_t MAX_ORPHAN_BLOCKS = 750;
/** Number of blocks that can be requested at any given time from a single peer. */
static const int32_t MAX_BLOCKS_IN_TRANSIT_PER_PEER = 128;
/** Timeout in seconds before considering a block download peer unresponsive. */
static const uint32_t BLOCK_DOWNLOAD_TIMEOUT  = 60;

/** The maximum size of a blk?????.dat file (since 0.8) */
static const uint32_t MAX_BLOCKFILE_SIZE = 0x8000000;  // 128 MiB
/** The pre-allocation chunk size for blk?????.dat files (since 0.8) */
static const uint32_t BLOCKFILE_CHUNK_SIZE = 0x1000000;  // 16 MiB
/** The pre-allocation chunk size for rev?????.dat files (since 0.8) */
static const uint32_t UNDOFILE_CHUNK_SIZE = 0x100000;  // 1 MiB
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int32_t COINBASE_MATURITY = 100;

/** max size of tx or block signature */
static const uint32_t MAX_SIGNATURE_SIZE = 100;

// -dbcache default (MiB)
static const int64_t nDefaultDbCache = 100;
// max. -dbcache in (MiB)
static const int64_t nMaxDbCache = sizeof(void *) > 4 ? 4096 : 1024;
// min. -dbcache in (MiB)
static const int64_t nMinDbCache = 4;

#ifdef USE_UPNP
static const int32_t fHaveUPnP = true;
#else
static const int32_t fHaveUPnP = false;
#endif

static const uint64_t kTotalBaseCoinCount           = 210000000;    // 210 million
static const uint64_t kYearBlockCount               = 10512000;     // one year = 365 * 24 * 60 * 60 / 3
static const uint64_t kMinDiskSpace                 = 52428800;     // Minimum disk space required
static const int32_t kContractScriptMaxSize         = 65536;        // 64 KB max for contract script size
static const int32_t kContractArgumentMaxSize       = 4096;         // 4 KB max for contract argument size
static const int32_t kCommonTxMemoMaxSize           = 100;          // 100 bytes max for memo size
static const int32_t kContractMemoMaxSize           = 100;          // 100 bytes max for memo size
static const int32_t kMostRecentBlockNumberLimit    = 1000;         // most recent block number limit

static const int32_t kMultisigNumberLimit           = 15;           // m-n multisig, refer to n
static const int32_t KMultisigScriptMaxSize         = 1000;         // multisig script max size
static const int32_t kRegIdMaturePeriodByBlock      = 100;          // RegId's mature period measured by blocks

static const uint16_t kMaxMinedBlocks               = 100;          // maximun cache size for mined blocks

static const string kContractScriptPathPrefix       = "/tmp/lua/";

static const string EMPTY_STRING = "";

#endif //CONFIG_CONST_H