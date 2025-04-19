# Tugas 2 OS_Week 2

**Nama:** Dinda Diyah Arifa  
**NRP:** 3124500034  
**Kelas:** 1 D3 IT B  

## Practice Exercises

### 1.1 What are the three main purposes of an operating system?  
**Answer:**  
An operating system has three main functions:

- To allocate the separate resources of the computer as needed to solve the problem given. The allocation process should be as fair and efficient as possible.
- To provide an environment for a computer user to execute programs on computer hardware in a convenient and efficient manner.
- As a control program it serves two major functions: 
  1. Supervision of the execution of user programs to prevent errors and improper use of the computer.
  2. Management of the operation and control of I/O devices.

### 1.2 When is it appropriate for the operating system to forsake efficiency and "waste" resources? Why is such a system not really wasteful?
**Answer:**  
Operating systems are designed to optimize the use of computing resources, but there are some situations where "wasting" resources is necessary for convenience, security, or reliability. Some examples are:
- Time-sharing
- Graphic interface (GUI)
- Virtualization
- Security
- Background services  
This is actually not wasteful because the benefits increase ease of use, data protection, and system stability.

### 1.3 What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?
**Answer:**  
One major difficulty that programmers need to overcome when writing an operating system for a real-time environment is meeting strict timing requirements. In a real-time system, tasks must be completed within specific time constraints to ensure the system functions correctly.

### 1.4 Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answers. 
**Answer:**  
**Arguments for including applications in the OS:**
- User Convenience: Users do not need to download additional software.
- Better Integration: Built-in applications can be optimized to work more smoothly with the OS.
- Consistent User Experience: Standard applications ensure a uniform experience across all devices.

**Arguments against including applications in the OS:**
- Focus on Resource Management: The OS should focus on managing resources, not providing user applications.
- Risk of Bloatware: Including applications that not all users need can increase system resource usage.
- Legal and Monopoly Issues: Bundling applications with the OS can lead to legal issues, such as antitrust cases.

### 1.5 How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security)?
**Answer:**  
The distinction between kernel mode and user mode provides a rudimentary form of protection in the following manner:
- Certain instructions can only be executed when the CPU is in kernel mode.
- Hardware devices can only be accessed when the program is executing in kernel mode.

### 1.6 Which of the following instructions should be privileged?  
- Set value of timer.  
- Read the clock.  
- Clear memory.  
- Issue a trap instruction.  
- Turn off interrupts.  
- Modify entries in device-status table.  
- Switch from user to kernel mode.  
- Access I/O device.  

**Answer:**  
The instructions that should be privileged are:
- **Issue a trap instruction:** Used to request services from the OS.
- **Turn off interrupts:** Can disrupt normal system operations.
- **Switch from user to kernel mode:** Changes the CPU's operating mode.
- **Access I/O device:** Directly interacts with hardware.

### 1.7	Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job or the operating system itself. Describe two difficulties that you think could arise with such a scheme.
**Answer:** 
1. The critical data such as passwords and access control information required by the operating system would have to be passed through or stored in unprotected memory slots, making it accessible to unauthorized users.
2. The operating system could never be updated or patched, since it is not modifiable or accessible by the user or the operating system itself.

### 1.8	Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes? 
**Answer:**  
1. **Distinguishing kernel code:** For example, a specific mode for USB drivers that allows them to run without switching to full kernel mode.
2. **Distinguishing user modes:** More granular user modes for stricter security policies, such as restricting code execution between users in the same group.

### 1.9	Timers could be used to compute the current time. Provide a short description of how this could be accomplished
**Answer:**  
Timers can take the help of a program that uses the following steps:
1. Sets the timer for some time later than the current time and goes to sleep.
2. An interrupt wakes up the program; that is when it updates its local state, which it uses to keep a record of the number of interrupts it has received so far.
3. Then it repeats this process of establishing timer interrupts and updating its local state when these timer interrupts are raised.

### 1.10	Give two reasons why caches are useful. What problems do they solve? What problems do they cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device? 
**Answer:**  
**Benefits of caches:**
- Speed up data exchange between components with different speeds.
- Reduce waiting time for slower devices.

**Problems caused by caches:**
- **Data consistency:** The cache must be updated if the data in the component changes.
- **Issues in multiprocessor systems:** Multiple processes may access the same data, causing conflicts.

**Why not make the cache as large as the device being cached?**
- Larger caches are more expensive.
- The cache may not have the same storage capacity as the original device (e.g., the cache cannot retain data when power is lost).

### 1.11 Distinguish between the client-server and peer-to-peer models of distributed systems.
**Answer:**  
**Client-Server Model:**
- The roles of the client and server are clearly separated.
- The client requests services, and the server provides services.

**Peer-to-Peer Model:**
- All nodes in the system are peers and can act as both clients and servers.
- Example: Sharing cooking recipes where each node can request or provide recipes.
