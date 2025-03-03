# TUGAS OS_WEEK 2_DINDA DIYAH ARIFA
# Nama: Dinda Diyah Arifa

# NRP: 3124500034

# Kelas: 1 D3 IT B

## **Practice Exercises**

### 1. What are the three main purposes of an operating system?

**Answer:**

An operating system has three main functions:

1. To allocate the separate resources of the computer as needed to solve the problem given. The allocation process should be as fair and efficient as possible.
2. To provide an environment for a computer user to execute programs on computer hardware in a convenient and efficient manner.
3. As a control program, it serves two major functions:
   - Supervision of the execution of user programs to prevent errors and improper use of the computer.
   - Management of the operation and control of I/O devices.

---

### 2. When is it appropriate for the operating system to forsake efficiency and "waste" resources? Why is such a system not really wasteful?

**Answer:**

Operating systems are designed to optimize the use of computing resources, but there are some situations where "wasting" resources is necessary for convenience, security, or reliability. Some examples are:

- **Time-Sharing**: Dividing CPU time among multiple users.
- **Graphic User Interface (GUI)**: Requires more resources for a user-friendly interface.
- **Virtualization**: Requires additional resources to run virtual machines.
- **Security**: Background services like antivirus or firewalls consume resources.
- **Background Services**: Automatic updates or system monitoring.

This is not wasteful because the benefits include increased ease of use, data protection, and system stability.

---

### 3. What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?

**Answer:**

One major difficulty that programmers need to overcome when writing an operating system for a real-time environment is meeting strict timing requirements. In a real-time system, tasks must be completed within specific time constraints to ensure the system functions correctly.

---

### 4. Should the operating system include applications such as web browsers and mail programs? Argue both sides.

**Answer:**

**Arguments for including applications in the OS:**

- **User Convenience**: Users do not need to download additional software.
- **Better Integration**: Built-in applications can be optimized to work more smoothly with the OS.
- **Consistent User Experience**: Standard applications ensure a uniform experience across all devices.

**Arguments against including applications in the OS:**

- **Focus on Resource Management**: The OS should focus on managing resources, not providing user applications.
- **Risk of Bloatware**: Including applications that not all users need can increase system resource usage.
- **Legal and Monopoly Issues**: Bundling applications with the OS can lead to legal issues, such as antitrust cases.

---

### 5. How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security)?

**Answer:**

The distinction between kernel mode and user mode provides a rudimentary form of protection in the following manner:

- Certain instructions can only be executed when the CPU is in kernel mode.
- Hardware devices can only be accessed when the program is executing in kernel mode.

This separation prevents user programs from directly accessing critical system resources, enhancing security.

---

### 6. Which of the following instructions should be privileged?

a. Set value of timer.  
b. Read the clock.  
c. Clear memory.  
d. Issue a trap instruction.  
e. Turn off interrupts.  
f. Modify entries in device-status table.  
g. Switch from user to kernel mode.  
h. Access I/O device.

**Answer:**

The instructions that should be privileged are:

- **Issue a trap instruction (d)**: Used to request services from the OS.
- **Turn off interrupts (e)**: Can disrupt normal system operations.
- **Switch from user to kernel mode (g)**: Changes the CPU's operating mode.
- **Access I/O device (h)**: Directly interacts with hardware.

---

### 7. Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job or the operating system itself. Describe two difficulties that could arise with such a scheme.

**Answer:**

The difficulties are:

1. **Critical Data Exposure**: Critical data such as passwords and access control information would have to be passed through or stored in unprotected memory slots, making it accessible to unauthorized users.
2. **Inability to Update or Patch**: The operating system could never be updated or patched, since it is not modifiable or accessible by the user or the operating system itself.

---

### 8. Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?

**Answer:**

Two possible uses of additional modes in CPUs:

1. **Distinguishing Kernel Code**: For example, a specific mode for USB drivers that allows them to run without switching to full kernel mode.
2. **Distinguishing User Modes**: More granular user modes for stricter security policies, such as restricting code execution between users in the same group.

---

### 9. Timers could be used to compute the current time. Provide a short description of how this could be accomplished.

**Answer:**

Timers can be used to compute the current time through the following steps:

1. Set the timer for some time later than the current time and put the program to sleep.
2. An interrupt wakes up the program, and it updates its local state, keeping a record of the number of interrupts received so far.
3. Repeat this process of setting timer interrupts and updating the local state when interrupts occur.

---

### 10. Give two reasons why caches are useful. What problems do they solve? What problems do they cause? If a cache can be made as large as the device for which it is caching, why not make it that large and eliminate the device?

**Answer:**

**Benefits of caches:**

- Speed up data exchange between components with different speeds.
- Reduce waiting time for slower devices.

**Problems caused by caches:**

- **Data Consistency**: The cache must be updated if the data in the component changes.
- **Issues in Multiprocessor Systems**: Multiple processes may access the same data, causing conflicts.

**Why not make the cache as large as the device being cached?**

- Larger caches are more expensive.
- The cache may not have the same storage capacity as the original device (e.g., the cache cannot retain data when power is lost).

---

### 11. Distinguish between the client-server and peer-to-peer models of distributed systems.

**Answer:**

**Client-Server Model:**

- The roles of the client and server are clearly separated.
- The client requests services, and the server provides services.

**Peer-to-Peer Model:**

- All nodes in the system are peers and can act as both clients and servers.
- Example: Sharing cooking recipes where each node can request or provide recipes.

---

```

This Markdown file is now ready for use and can be viewed or edited in any Markdown-compatible editor.
