# Transit Identity - EOSIO Smart Contracts

## ACTION

- [`add`](#action-add)
- [`remove`](#action-remove)
- [`tier`](#action-tier)
- [`provider`](#action-provider)

## TABLE

- [`identity`](#identity-table)
- [`tier`](#tier-table)
- [`provider`](#provider-table)

## ACTION `add`

Add transit identity to the smart contract table

- Authority: `provider`

### params

- `{name} provider` - provider account name
- `{name} account` - identity account name
- `{public_key} key` - public key that was used to sign the proof of identity
- `{uint8_t} tier` - identity tier assosiated with identity report
- `{string} metadata` - additional metadata about report

### example

```bash
cleos push action identity add '["transit", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "0x04136750a3df9f3cd19e06f60af25f596c74aa0c"]' -p transit
```

## ACTION `remove`

Remove identity report from the smart contract table

- Authority: `provider`

### params

- `{name} provider` - provider account name
- `{name} account` - identity account name

### example

```bash
cleos push action identity remove '["transit", "myaccount"]' -p transit
```

## ACTION `tier`

Add metadata for tier

- Authority: `get_self()`

### params

- `{uint8_t} tier` - identity tier
- `{name} name` - identity tier name
- `{string} metadata` - identity tier metadata

### example

```bash
cleos push action identity tier '[1, "eth", "ETH identity"]' -p identity
```

## ACTION `provider`

Add authorized light kyc provider

- Authority: `get_self()` (if does not exist)
- Authority: `provider` or `get_self()` (if already exist)

### params

- `{name} name` - light kyc provider account name
- `{string} metadata` - light kyc provider metadata

### example

```bash
cleos push action identity provider '["transit", "FAST Transit"]' -p identity
```

## TABLE `identity`

- Scope: `provider`

### params

- `{name} name` - identity account name
- `{public_key} key` - public key that was used to sign the proof of identity
- `{uint8_t} tier` - identity tier assosiated with identity report
- `{string} metadata` - additional metadata about report
- `{checksum256} trx_id` - identity creation transaction id
- `{time_point_sec} timestamp` - identity creation timestamp

### example

```json
{
  "name": "myaccount",
  "key": "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",
  "tier": 1,
  "metadata": "0x04136750a3df9f3cd19e06f60af25f596c74aa0c",
  "trx_id": "f0889d11501fc83ff52d8af62e2d1552193c728e874d9bb559f30a0012deee3e",
  "timestamp": "2019-09-09T00:00:00"
}
```

## TABLE `provider`

### params

- `{name} provider` - provider account name
- `{string} metadata` - provider metadata

### example

```json
{
  "name": "transit",
  "metadata": "FAST Transit"
}
```

## TABLE `tier`

### params

- `{uint8_t} tier` - identity tier
- `{name} name` - identity tier name
- `{string} metadata` - identity tier metadata

### example

```json
{
  "tier": 1,
  "name": "eth",
  "metadata": "ETH identity"
}
```
