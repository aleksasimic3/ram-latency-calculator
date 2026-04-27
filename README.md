A simple command-line tool for calculating **RAM latency** based on memory clock speed and CAS latency (CL).  
It helps you compare multiple RAM configurations and outputs the results in ascending order of latency.

---

## 📖 Overview
Memory latency is a critical factor in system performance.  
This tool computes the **true latency (ns)** using the formula:



Latency = $\frac{CAS \times 2000}{RAM\ Speed\ (MT/s)}$



Where:
- **CAS** = Column Access Strobe latency (CL)
- **RAM Speed** = Effective DDR transfer rate in MT/s (e.g., 3200, 3600)

---

## ⚙️ Usage

```bash
ddrLatency.exe ramspeed1 latency1 [optional-ramspeed2 optional-latency2 ...]
```

## Example
```bash
ddrLatency.exe 3200 16 3600 18 2400 15
```

## Output
```code
3200MT/s CL16 : 10.00ns
3600MT/s CL18 : 10.00ns
2400MT/s CL15 : 12.50ns
```
