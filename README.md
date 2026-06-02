# BytesFactory
The purpose of this simple &amp; little project is to master byte manipulation allowing us to optimize RAM usage. The use of this technique is quit common in constrained environments.


--------------------- Scenario ChatGTP ---------------------


Satellite BlackBox

Overview

The goal of this project is to explore low-level programming through byte and bit manipulation techniques commonly used in embedded and constrained environments.

In this scenario, you are developing the onboard communication system of a small space probe called Astra-9.
The probe is orbiting an icy moon near Jupiter and must operate with extremely limited resources:

* very small RAM capacity,
* restricted bandwidth,
* unstable signal transmission caused by cosmic radiation.

Because every transmitted byte consumes valuable energy, the system must optimize memory usage and data transmission as efficiently as possible.

This project focuses on:

* bitwise operations,
* binary data representation,
* data packing,
* memory optimization,
* binary serialization,
* checksum generation and validation.

⸻

Objectives

Through this project, you will learn how to:

* manipulate bits and bytes,
* pack multiple values into a single byte,
* optimize RAM usage,
* serialize binary data,
* detect transmission errors,
* design lightweight communication protocols.

⸻

Features

1. System Flags

The spacecraft status is stored inside a single byte using bit flags.

Each bit represents a system state:

Bit	Description
0	Engine status
1	Shield status
2	Antenna status
3	Emergency mode
4-7	Reserved

Example:

flags |= (1 << 2);

⸻

2. Telemetry Compression

Telemetry data must be compressed into as few bytes as possible.

The system stores:

* temperature, // Plage entre -40 et +70 on va dire. 7 bits
* radiation level, // Entre 0 et 16. 5 bits
* battery percentage, // Entre 0 et 100. 7 bits
* actual speed, // Entre 0 et 1 400 (en orbite MEO) en pas de 10 km/h. 11 bits

inside compact binary packets using manual bit packing techniques.
Total necessary bits : 30.

⸻

3. Binary Packet Transmission

The probe communicates with Earth using lightweight binary packets.

Example packet structure:

Byte	Content
0	Temperature
1	Radiation
2	Battery
3	System flags
4	Checksum

⸻

4. Error Detection

Cosmic radiation may corrupt transmitted data.

To ensure packet integrity, the system implements a checksum validation mechanism.

Example:

checksum = b0 ^ b1 ^ b2 ^ b3;

⸻

Missions

Mission 1 — Flag Management

Implement a system capable of:

* enabling flags,
* disabling flags,
* checking flag states.

Suggested functions:

void enable_flag(uint8_t* flags, int bit);
void disable_flag(uint8_t* flags, int bit);
bool is_flag_enabled(uint8_t flags, int bit);

⸻

Mission 2 — Data Packing

Store multiple telemetry values inside only a few bytes by manually packing bits.

Example constraints:

* temperature: 0 → 127
* radiation: 0 → 15
* battery: 0 → 100

⸻

Mission 3 — Packet Serialization

Create and validate binary packets.

Suggested structure:

typedef struct
{
    uint8_t data[4];
    uint8_t checksum;
} Packet;

⸻

Mission 4 — Emergency Mode

If:

* battery level becomes critical,
* radiation exceeds a safe threshold,

the spacecraft automatically switches to emergency mode and reduces its activity to preserve energy.

⸻

Advanced Challenges

Binary Logging

Create compact binary logs such as:

00101101 11100010

Run-Length Encoding (RLE)

Implement a simple compression algorithm:

AAAAABBBCC
↓
5A3B2C

Custom Space Protocol

Design a minimal binary communication protocol:

[HEADER][DATA][CHECKSUM][END]

⸻

Recommended Languages

Recommended:

* C
* C++
* Rust

⸻

Learning Outcomes

By completing this project, you will gain a deeper understanding of:

* low-level memory representation,
* embedded systems programming,
* binary communication protocols,
* RAM optimization techniques,
* real-world bit manipulation strategies used in systems programming and game/network engines.