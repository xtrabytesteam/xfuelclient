// Copyright (c) 2009-2012 The Bitcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (  0, uint256("0x0000079dbd0ea897d280a549dc6defcab1128982d75468927cdfe86e6b85883b"))
        (  100000, uint256("0x537ddd96a889f42c3eb4323a8ed3763514c6272dadb01b5a6a2f613db0e8534a"))
        (  200000, uint256("0x1fe3f491d4773b12a8860de71cd31bc002639d3b5f5a1cdd977ed6d82ac40cf3"))
        (  300000, uint256("0x176434f15f7e63ccdd848c0d1ce54240b605b76e9e593478e98aaf632bb5376c"))
        (  400000, uint256("0xc612263ec04aff614935005e9b2cf24ff11fe729574a70bb9899a9f31e4ebde3"))
        (  500000, uint256("0x6ba21dd24eb8fbf9af353bf1a20aee071f01791d695f8619df4581af30934fcb"))
        (  600000, uint256("0xde63cea640e3b05a46199954af0daa26df0849bceab898a794529dea64e75fbb"))
        (  700000, uint256("0xc1a2fa85e118bd0050a4f207c00f65eaba05252c93a7976125746cee2db9dfe6"))
        (  800000, uint256("0x888e4f95c01d91db98769912f39efe29086b401816029aa998167908ca0982fa"))
        (  900000, uint256("0xaaca376af65f64501d19e5283e1f7d8c7ab1d389c5dd9d099a5f88b540bc2be4"))
        (  920000, uint256("0xc7beae7e90036c3ff7afc7d3c054169fcfd7e044a157a1cfc96ef7a858103296"))
        (  923000, uint256("0xae795a122f3044b0c4e5d88f20eba5c7f4ef2b55b74eec37e2430e3ac8ec7586"))
	(  925000, uint256("0x2e83dbc508a4a9fe862b12b725c5ae8d77ab8089065f3bafb05f10b2a1e57bc5"))
	(  930000, uint256("0xa93e3dfb49fe5cb0dbc6b02e568ce4403741e98d206dc3424f830e640dc0d483"))
	(  935000, uint256("0xdce6793347366a09f9d1c401fa9258f31f67180a737baf5e70fa50fdfa59ba8c"))   
	(  940000, uint256("0xa3e614291ce446e96c571178d883eefc1f01e0f315486144137531305435be24"))
	(  945000, uint256("0x5fc924e33e4af4b499caf77bceac4c3a1be20534ac1fd17b44612bbda1eea566"))
	(  950000, uint256("0xf4816e16bb6348d00b5a16642e1753d194cabe5b5ab4e953ab6e7e26e82f0ecf"))
	(  955000, uint256("0xe2fc30b11b3d3a75f8cb642f4239f6cdd78e2e87a5a975c32ff5e2aac6465ac0"))
	(  960000, uint256("0xd08c0e78011f647f02948e7712c7f173f205df55486167348205e9dfa07390c8"))
	(  965000, uint256("0xcded08a349317d7f6cc1ace9123ea33d8f68293fa80d4175333c711fdc7dcc9a"))
	(  970000, uint256("0xf8d3d075b2351f21d715475ea5c5453cbe1aed82ded6b3f52fea7d914b66c3ed"))
	(  975000, uint256("0xf5a95a323738b24c9157367a4a3571fefd2de7cfc51c23c038b86b914f27ba59"))
	(  980000, uint256("0xefffc9011655cc125105c4a611467b106ac0dc2f13f36c73a1b833e1150c8eb4"))
	(  985000, uint256("0x116beade5322a138433a07938e6c821c40a59faff610b084b89adf85a89b1da2"))
	(  990000, uint256("0xff9f4bf21addabe1890655c8fb97751ef9adf49f838e7dcbb2c23b6c468d2361"))
	(  995000, uint256("0x93c8c9280749b8f5510913a884b00b19441309f23b2ab523f645a6a70cd4fe90"))
	(  1000000, uint256("0xdc1bda0dd688447c2d51f6bbd5e54182858b11f7f8f1febddebb2d843eb667df"))
	(  1025000, uint256("0x121bda2b19fa9e041dc2c976eb80ae9a50aef2695d7f9d0ba97a00aac38bfeea"))
	(  1050000, uint256("0xb260690ee9e9913f25403e66b3b8aa907ca95571ba8bb08a5369fced89381153"))
	(  1050500, uint256("0x7f95d176914fb3b5c6dc80128eb82e0d4f98424b0e7b2a327cd64d21974123e2"))   
	(  1051000, uint256("0x4ee954986f75b196f974cc6c7e2a3409ef86d0348eecee9684f6d9894a04dea5"))
	(  1051500, uint256("0x2e44e462fc04b9d28043c7a9de3ac453ba1ebfa5cbb3239d039da1ccf545b9f0"))
	(  1052000, uint256("0x42fb2f052705bd420497fbce9906e48ac4bc2923f268b38f73bb879c83833075"))
	(  1052500, uint256("0x779d7738a27cfd02ef250b351449e0d3ed84ad4b07b66d66f76179deaac66cf9"))
	(  1053000, uint256("0xb0d1bacd7b9f01978b094877f6c38ec3fc8d8fbe5596a6f6a573b52bc6329410"))
	(  1053500, uint256("0x0ba553621ec358e886712490fe436dbb894b46c5559a58763b451a454383b9a6"))
        (  1054000, uint256("0x3ee4464cc0bb77ac52689c59eb54976d16b41a0ab5aafd6ba587d4b38c8c2251"))
	(  1054500, uint256("0x3ea4b9bb07c963451efbceeb663a33d80b3dc736154fcccbe1da6f2582ef79c4"))
	(  1055000, uint256("0xb8cb5c9856338d298b52e01cdfd1a44c28c726edee757b67d20d8c00c1caa6ba"))
	(  1055500, uint256("0x82c8a87a8cdb7cce8abb3f4a71686725b041121434c154c21c3e8445c5562134"))
	(  1056000, uint256("0x4fe1e32598fe9161208c21a5db3703f8e4a46adf35a8b23fa03c586d88f05d71"))
	(  1056500, uint256("0x7aefc006cc387e8a7583ab783fb5bfe770a530d530b8135e379dcb23bdd1d83e"))
	(  1057000, uint256("0x589292d0c084202f33e5df92261505d74f2bb4c15a8f6d7ff5f16d1b585d9d6b"))
	(  1057500, uint256("0x9932bc225c8e03633c0270aef31d51210b018446e817fb503724f71735409956"))
	(  1057600, uint256("0x2698e8e7888df304284a167a4a020462681a4314cfb7d32b4c1ad38e2afdc267"))
	(  1057700, uint256("0x5e2497797191aa4c36e3d5bea4a4638a8043359ec4436b4c9dbd76374680af34"))
	(  1057800, uint256("0x3899c07becdbfeaa6e871008b0d125d1e06c2ea7ec036b22c7eb3dfb92c96bd2"))
	(  1057900, uint256("0x7243b3e6485ada1cebae843cf8fc77c4b370fa6c836702d742821bd64aa7fd47"))
	    
        ;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1394545186, // * UNIX timestamp of last checkpoint block
        0,    // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        1000.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet = 
        boost::assign::map_list_of
        (   0, uint256(hashGenesisBlock))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1394545201,
        0,
        100
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
	
	uint256 GetLatestHardenedCheckpoint()
    {
        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;
        return (checkpoints.rbegin()->second);
    }
}
