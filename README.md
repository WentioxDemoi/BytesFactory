# BytesFactory

## Overview

The purpose of this project is to learn low-level memory manipulation through practical exercises involving:

- bitwise operations,
- binary representation,
- bit packing,
- binary serialization,
- checksum generation,
- error detection.

These techniques are commonly used in:

- embedded systems,
- network protocols,
- game engines,
- IoT devices,
- space and aerospace software.

---

# Scenario

You are developing the communication system of a small space probe called Astra-9.

The probe operates under severe constraints:

- limited RAM,
- restricted communication bandwidth,
- unstable transmissions caused by cosmic radiation.

To reduce memory consumption and transmission costs, telemetry data must be represented and transmitted using compact binary formats.

---

# Project Goals

The project is divided into several independent missions.

Each mission introduces a different concept used in low-level programming.

---

# Mission 1 — System Flags

The spacecraft stores multiple system states inside a single byte.

Each bit represents one status flag.

| Bit | Description |
|------|------------|
| 0 | Engine enabled |
| 1 | Shield enabled |
| 2 | Antenna enabled |
| 3 | Emergency mode |
| 4-7 | Reserved |

Example:

c flags |= (1 << 2); 

Expected features:

- enable a flag,
- disable a flag,
- check if a flag is enabled.

Suggested API:

c void enable_flag(uint8_t* flags, int bit); void disable_flag(uint8_t* flags, int bit); bool is_flag_enabled(uint8_t flags, int bit); 

---

# Mission 2 — Telemetry Bit Packing

Telemetry values must be compressed into a single 32-bit integer.

Available telemetry:

| Field | Range | Required bits |
|---------|---------|---------|
| Temperature | 0 → 127 | 7 |
| Radiation | 0 → 31 | 5 |
| Battery | 0 → 100 | 7 |
| Speed | 0 → 1400 | 11 |

Total:

text 7 + 5 + 7 + 11 = 30 bits 

All values must therefore fit inside a single:

c uint32_t 

Example layout:

text 31                             0
+--+-----------+-------+-----+-------+ 
|00|   Speed   |Battery| Rad | Temp  | 
+--+-----------+-------+-----+-------+    
    11 bits     7 bits 5 bits 7 bits 

Expected features:

c uint32_t packTelemetry(...); Telemetry unpackTelemetry(uint32_t packed); 

Goal:

- learn bit masks,
- learn bit shifts,
- optimize memory usage.

---

# Mission 3 — Binary Packet Serialization

Once telemetry has been packed into a 32-bit value, it must be prepared for transmission.

The packed integer is split into four bytes.

Example:

text uint32_t packedTelemetry
         ↓ 
+------+------+------+------+ 
| B0   | B1   | B2   | B3   | 
+------+------+------+------+ 

Packet format:

c typedef struct {     
    uint8_t data[4];     
    uint8_t checksum; 
} Packet; 

Expected features:

c Packet serialize(uint32_t packed); uint32_t deserialize(const Packet* packet); 

Goal:

- convert binary data into a transmissible format,
- understand serialization.

---

# Mission 4 — Error Detection

Communication may be corrupted by cosmic radiation.

Each packet therefore contains a checksum.

Example checksum:

c checksum =     data[0] ^     data[1] ^     data[2] ^     data[3]; 

Expected features:

c uint8_t computeChecksum(const Packet* packet); bool validatePacket(const Packet* packet); 

Goal:

- detect transmission errors,
- validate received packets.

---

# Mission 5 — Emergency Mode

The spacecraft must automatically enter emergency mode when operating conditions become unsafe.

Example rules:

- battery level below 15%,
- radiation level above a predefined threshold.

Expected behavior:

text Low battery         OR High radiation         ↓ Enable emergency flag 

Goal:

- combine previous modules,
- manipulate flags automatically.

---

# Advanced Challenges

## Binary Logging

Store telemetry using compact binary logs.

Example:

text 00101101 11100010 

---

## Run-Length Encoding (RLE)

Implement a simple compression algorithm.

Example:

text 
AAAAABBBCC
↓ 
5A3B2C 

---

## Custom Space Protocol

Design your own protocol.

Example:

text [HEADER][DATA][CHECKSUM][END] 

Possible additions:

- packet type,
- protocol version,
- sequence number,
- acknowledgment system.

---

# Learning Outcomes

By completing this project you will gain experience with:

- bitwise operations,
- memory optimization,
- binary serialization,
- communication protocols,
- checksum validation,
- embedded programming concepts.