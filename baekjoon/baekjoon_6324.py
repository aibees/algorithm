n = int(input())
for i in range(1,n+1) :
    numbering = "URL #" + str(i)
    urls = input()
    # split Protocol
    host = ""
    port = "<default>"
    path = "<default>"
    first = urls.split("://")[0]
    protocol = first
    next_str = urls[len(first)+3:]
    colon_idx = 0; colon_flag = False; slash_idx = 0; slash_flag = False
    for i in next_str :
        if i is ':' :
           colon_flag = True
        else :
            if not colon_flag :
                colon_idx += 1
        if i is '/' :
            slash_flag = True
        else :
            if not slash_flag :
                slash_idx += 1
        if colon_flag and slash_flag :
            break

    if colon_idx is len(next_str) and slash_idx is len(next_str) :
        host = next_str
        print(numbering)
        print("Protocol = " + protocol)
        print("Host     = " + host)
        print("Port     = " + port)
        print("Path     = " + path + "\n")
    elif colon_idx < len(next_str) and colon_idx < slash_idx :
        host, port = (next_str[:slash_idx]).split(":")
        path = next_str[slash_idx+1:]
        if path is "" :
            path = "<default>"
        if port is "" :
            port = "<default>"
        print(numbering)
        print("Protocol = " + protocol)
        print("Host     = " + host)
        print("Port     = " + port)
        print("Path     = " + path + "\n")
    elif colon_idx is len(next_str) and slash_idx < len(next_str) :
        host = next_str[:slash_idx]
        path = next_str[slash_idx+1:]

        print(numbering)
        print("Protocol = " + protocol)
        print("Host     = " + host)
        print("Port     = " + port)
        print("Path     = " + path + "\n")
    
    