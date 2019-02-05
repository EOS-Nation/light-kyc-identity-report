# EOS Detective Reports

> EOSIO based smart contract that publishes token forensic reports on chain.

## How to Install

[`eosio.cdt`](https://github.com/EOSIO/eosio.cdt) & [`cleos`](https://github.com/EOSIO/eos) must already be installed installed.

**Mac OS X Brew Install**

**install `eosio-cpp`**
```
$ brew tap eosio/eosio.cdt
$ brew install eosio.cdt
```
**install `cleos`**
```
$ brew tap eosio/eosio
$ brew install eosio
```

**Build .wasm**

```
$ git clone git@github.com:EOS-Nation/eos-detective-reports.git
$ cd eos-detective-reports/src
$ eosio-cpp detective.cpp -o detective.wasm
```

**Deploy Contract**

`<account>` is the account name used to deploy the smart contract.

```
$ cleos set contract <account> . detective.wasm detective.abi
```

## How to Use

Get Account Data

```
$ cleos get table <contract> <scope> accounts
```

Push new report

```
$ cleos push action <contract> post '["account",score,"metadata"]' -p <account>@active
```

Update report

```
$ cleos push action <contract> post '["account",score,"metadata"]' -p <account>@active
```

Remove report before expiry

```
$ cleos push action <contract> post '["account",0,""]' -p <account>@active
```

Remove report after expiry

```
$ cleos push action <contract> expire '["account"]' -p <account>@active
```

## Tables

**accounts**

| variable  | type    | description        |
|-----------|---------|--------------------|
| account   | account | EOSIO Account Name |
| score     | integer | Token Weighted Score     |
| metadata  | JSON    | Token Forensics Metadata |
| timestamp | datetime| Last updated             |
