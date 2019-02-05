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

## Setup Custom Permissions

It is recommended that you set custom permissions for the following reasons:
- Not exposing your `active` or `owner` private key
- Permission has explicit actions it can perform (ex: `post` & `expire`)

```
$ cleos set account permission <account> <permission> <public key> <parent>
$ cleos set action permission <account> <code> <type> <requirement>
```

**Example**

```
$ cleos set account permission account12345 reports EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV active
$ cleos set action permission account12345 <contract> post reports
```