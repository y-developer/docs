# Networking Related Commands

## Find DNS records of a website

```bash
nslookup -type=<type> <website_url>
```

### DNS Recode Types

| Type  | Description                                                                                                                                    |
| ----- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| `A`     | (Address) record: retrieves the IP address of a domain.                                                                                        |
| `AAAA`  | (IPv6 Address) record: retrieves the IPv6 address of a domain.                                                                                 |
| `CNAME` | (Canonical Name) record: retrieves the canonical domain name for a domain alias.                                                               |
| `MX `   | (Mail Exchange) record: retrieves the mail servers responsible for accepting incoming emails for a domain.                                     |
| `NS `   | (Name Server) record: retrieves the name servers for a domain.                                                                                 |
| `PTR`   | (Pointer) record: retrieves the domain name associated with an IP address.                                                                     |
| `SOA`   | (Start of Authority) record: retrieves information about the primary name server for a domain and the email address of the responsible person. |
| `SRV`   | (Service) record: retrieves information about available services for a domain.                                                                 |
| `TXT`   | (Text) record: retrieves arbitrary text data associated with a domain.                                                                         |

## Find currently open ports in pc

```bash
sudo netstat -tlnp
```

If netstat not working, Install `net-tools` package
```bash
sudo apt-get update
```

```bash
sudo apt-get install net-tools
```
