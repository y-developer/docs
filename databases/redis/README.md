# Redis Commands Reference

## Common

| Command                | Description                     |
|------------------------|---------------------------------|
| EXISTS <key>           | Check if a key exists           |
| DEL <key>              | Delete a key                    |
| EXPIRE <key> <seconds> | Set a timeout on a key          |
| TTL <key>              | Get the time to live for a key  |
| FLUSHALL               | Remove all keys from all databases |

## String
| Command        | Description                |
|----------------|----------------------------|
| SET <key> <value> <seconds> | Set the string value of a key |
| GET <key>      | Get the value of a key      |

## Keys
| Command        | Description                     |
|----------------|---------------------------------|
| KEYS <pattern> | Find all keys matching the given pattern |
| RENAME <key> <newkey> | Rename a key                  |
| RENAMENX <key> <newkey> | Rename a key, only if the new key does not exist |
| TYPE <key>     | Determine the type stored at key |
| RANDOMKEY      | Return a random key from the keyspace |

## Integer
| Command        | Description                     |
|----------------|---------------------------------|
| INCR <key>     | Increment the integer value of a key by 1 |
| DECR <key>     | Decrement the integer value of a key by 1 |
| INCRBY <key> <increment> | Increment the integer value of a key by the given amount |
| DECRBY <key> <decrement> | Decrement the integer value of a key by the given amount |

## List
| Command        | Description                     |
|----------------|---------------------------------|
| LPUSH <key> <value> | Prepend a value to a list (left side)      |
| RPUSH <key> <value> | Append a value to a list (right side)     |
| LPOP <key>     | Remove and get the first element of a list (left side) |
| RPOP <key>     | Remove and get the last element of a list (right side)  |
| LRANGE <key> <start> <stop> | Get a range of elements from a list (last item is -1) |

## Set (Same as List but every member is unique)
| Command        | Description                     |
|----------------|---------------------------------|
| SADD <key> <member> | Add a member to a set            |
| SREM <key> <member> | Remove a member from a set       |
| SMEMBERS <key> | Get all the members in a set     |

## Hash (Dictionary of key-value pairs)
| Command        | Description                     |
|----------------|---------------------------------|
| HSET <key> <field> <value> | Set the string value of a field in a hash |
| HGET <key> <field> | Get the value of a field in a hash      |
| HDEL <key> <field> | Delete a field from a hash       |
| HGETALL <key>  | Get all the fields and values in a hash |
| HEXISTS <key> <field> | Check if a field exists in a hash |

## Sorted Set (Set with a score for each member)
| Command        | Description                     |
|----------------|---------------------------------|
| ZADD <key> <score> <member> | Add a member with a score to a sorted set |
| ZREM <key> <member> | Remove a member from a sorted set       |
| ZRANGE <key> <start> <stop> | Get a range of members in a sorted set, by index (last item is -1) |
| ZSCORE <key> <member> | Get the score associated with a member in a sorted set |
| ZRANGEBYSCORE <key> <min> <max> | Get a range of members in a sorted set, by score |

## Pub/Sub
| Command        | Description                     |
|----------------|---------------------------------|
| PUBLISH <channel> <message> | Post a message to a channel      |
| SUBSCRIBE <channel> | Listen for messages on a channel  |
| UNSUBSCRIBE <channel> | Stop listening for messages on a channel |

## Transactions
| Command        | Description                     |
|----------------|---------------------------------|
| MULTI          | Start a transaction             |
| EXEC           | Execute all commands issued after MULTI |
| DISCARD        | Discard all commands issued after MULTI |
| WATCH <key>    | Watch a key for conditional execution of a transaction |
| UNWATCH        | Unwatch all keys                |

## Scripting
| Command        | Description                     |
|----------------|---------------------------------|
| EVAL <script> <numkeys> <key1> ... <keyN> | Execute a Lua script            |
| EVALSHA <sha1> <numkeys> <key1> ... <keyN> | Execute a cached Lua script by its SHA1 hash |

## Server
| Command        | Description                     |
|----------------|---------------------------------|
| INFO           | Get information and statistics about the server |
| CONFIG GET <parameter> | Get the value of a configuration parameter |
| CONFIG SET <parameter> <value> | Set the value of a configuration parameter |
| SAVE           | Synchronously save the dataset to disk |
| BGSAVE         | Asynchronously save the dataset to disk |
| SHUTDOWN       | Shut down the server            |
| LASTSAVE       | Get the UNIX time stamp of the last successful save to disk |