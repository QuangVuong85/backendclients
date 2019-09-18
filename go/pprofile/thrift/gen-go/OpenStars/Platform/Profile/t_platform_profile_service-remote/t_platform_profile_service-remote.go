// Autogenerated by Thrift Compiler (0.11.0)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING

package main

import (
        "context"
        "flag"
        "fmt"
        "math"
        "net"
        "net/url"
        "os"
        "strconv"
        "strings"
        "git.apache.org/thrift.git/lib/go/thrift"
        "OpenStars/Platform/Profile"
)


func Usage() {
  fmt.Fprintln(os.Stderr, "Usage of ", os.Args[0], " [-h host:port] [-u url] [-f[ramed]] function [arg1 [arg2...]]:")
  flag.PrintDefaults()
  fmt.Fprintln(os.Stderr, "\nFunctions:")
  fmt.Fprintln(os.Stderr, "  string setExtData(TKey uid, string extKey, string extValue)")
  fmt.Fprintln(os.Stderr, "  string getExtData(TKey uid, string extKey)")
  fmt.Fprintln(os.Stderr, "  bool setTrustedEmail(TKey uid, string email, bool isTrusted)")
  fmt.Fprintln(os.Stderr, "  bool removeTrustedEmail(TKey uid, string email)")
  fmt.Fprintln(os.Stderr, "  bool setTrustedMobile(TKey uid, string email, bool isTrusted)")
  fmt.Fprintln(os.Stderr, "  bool removeTrustedMobile(TKey uid, string mobile)")
  fmt.Fprintln(os.Stderr, "  bool setSocialInfo(TKey uid, string socialType, TSocialProfile socialProfile)")
  fmt.Fprintln(os.Stderr, "  bool removeSocialInfo(TKey uid, string socialType, TSocialProfile socialProfile)")
  fmt.Fprintln(os.Stderr, "  TErrorCode putData(TKey key, TPlatformProfile data)")
  fmt.Fprintln(os.Stderr, "  TDataResult getData(TKey key)")
  fmt.Fprintln(os.Stderr)
  os.Exit(0)
}

func main() {
  flag.Usage = Usage
  var host string
  var port int
  var protocol string
  var urlString string
  var framed bool
  var useHttp bool
  var parsedUrl *url.URL
  var trans thrift.TTransport
  _ = strconv.Atoi
  _ = math.Abs
  flag.Usage = Usage
  flag.StringVar(&host, "h", "localhost", "Specify host and port")
  flag.IntVar(&port, "p", 9090, "Specify port")
  flag.StringVar(&protocol, "P", "binary", "Specify the protocol (binary, compact, simplejson, json)")
  flag.StringVar(&urlString, "u", "", "Specify the url")
  flag.BoolVar(&framed, "framed", false, "Use framed transport")
  flag.BoolVar(&useHttp, "http", false, "Use http")
  flag.Parse()
  
  if len(urlString) > 0 {
    var err error
    parsedUrl, err = url.Parse(urlString)
    if err != nil {
      fmt.Fprintln(os.Stderr, "Error parsing URL: ", err)
      flag.Usage()
    }
    host = parsedUrl.Host
    useHttp = len(parsedUrl.Scheme) <= 0 || parsedUrl.Scheme == "http"
  } else if useHttp {
    _, err := url.Parse(fmt.Sprint("http://", host, ":", port))
    if err != nil {
      fmt.Fprintln(os.Stderr, "Error parsing URL: ", err)
      flag.Usage()
    }
  }
  
  cmd := flag.Arg(0)
  var err error
  if useHttp {
    trans, err = thrift.NewTHttpClient(parsedUrl.String())
  } else {
    portStr := fmt.Sprint(port)
    if strings.Contains(host, ":") {
           host, portStr, err = net.SplitHostPort(host)
           if err != nil {
                   fmt.Fprintln(os.Stderr, "error with host:", err)
                   os.Exit(1)
           }
    }
    trans, err = thrift.NewTSocket(net.JoinHostPort(host, portStr))
    if err != nil {
      fmt.Fprintln(os.Stderr, "error resolving address:", err)
      os.Exit(1)
    }
    if framed {
      trans = thrift.NewTFramedTransport(trans)
    }
  }
  if err != nil {
    fmt.Fprintln(os.Stderr, "Error creating transport", err)
    os.Exit(1)
  }
  defer trans.Close()
  var protocolFactory thrift.TProtocolFactory
  switch protocol {
  case "compact":
    protocolFactory = thrift.NewTCompactProtocolFactory()
    break
  case "simplejson":
    protocolFactory = thrift.NewTSimpleJSONProtocolFactory()
    break
  case "json":
    protocolFactory = thrift.NewTJSONProtocolFactory()
    break
  case "binary", "":
    protocolFactory = thrift.NewTBinaryProtocolFactoryDefault()
    break
  default:
    fmt.Fprintln(os.Stderr, "Invalid protocol specified: ", protocol)
    Usage()
    os.Exit(1)
  }
  iprot := protocolFactory.GetProtocol(trans)
  oprot := protocolFactory.GetProtocol(trans)
  client := Profile.NewTPlatformProfileServiceClient(thrift.NewTStandardClient(iprot, oprot))
  if err := trans.Open(); err != nil {
    fmt.Fprintln(os.Stderr, "Error opening socket to ", host, ":", port, " ", err)
    os.Exit(1)
  }
  
  switch cmd {
  case "setExtData":
    if flag.NArg() - 1 != 3 {
      fmt.Fprintln(os.Stderr, "SetExtData requires 3 args")
      flag.Usage()
    }
    argvalue0, err42 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err42 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    argvalue2 := flag.Arg(3)
    value2 := argvalue2
    fmt.Print(client.SetExtData(context.Background(), value0, value1, value2))
    fmt.Print("\n")
    break
  case "getExtData":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "GetExtData requires 2 args")
      flag.Usage()
    }
    argvalue0, err45 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err45 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    fmt.Print(client.GetExtData(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "setTrustedEmail":
    if flag.NArg() - 1 != 3 {
      fmt.Fprintln(os.Stderr, "SetTrustedEmail requires 3 args")
      flag.Usage()
    }
    argvalue0, err47 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err47 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    argvalue2 := flag.Arg(3) == "true"
    value2 := argvalue2
    fmt.Print(client.SetTrustedEmail(context.Background(), value0, value1, value2))
    fmt.Print("\n")
    break
  case "removeTrustedEmail":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "RemoveTrustedEmail requires 2 args")
      flag.Usage()
    }
    argvalue0, err50 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err50 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    fmt.Print(client.RemoveTrustedEmail(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "setTrustedMobile":
    if flag.NArg() - 1 != 3 {
      fmt.Fprintln(os.Stderr, "SetTrustedMobile requires 3 args")
      flag.Usage()
    }
    argvalue0, err52 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err52 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    argvalue2 := flag.Arg(3) == "true"
    value2 := argvalue2
    fmt.Print(client.SetTrustedMobile(context.Background(), value0, value1, value2))
    fmt.Print("\n")
    break
  case "removeTrustedMobile":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "RemoveTrustedMobile requires 2 args")
      flag.Usage()
    }
    argvalue0, err55 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err55 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    fmt.Print(client.RemoveTrustedMobile(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "setSocialInfo":
    if flag.NArg() - 1 != 3 {
      fmt.Fprintln(os.Stderr, "SetSocialInfo requires 3 args")
      flag.Usage()
    }
    argvalue0, err57 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err57 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    arg59 := flag.Arg(3)
    mbTrans60 := thrift.NewTMemoryBufferLen(len(arg59))
    defer mbTrans60.Close()
    _, err61 := mbTrans60.WriteString(arg59)
    if err61 != nil {
      Usage()
      return
    }
    factory62 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt63 := factory62.GetProtocol(mbTrans60)
    argvalue2 := Profile.NewTSocialProfile()
    err64 := argvalue2.Read(jsProt63)
    if err64 != nil {
      Usage()
      return
    }
    value2 := argvalue2
    fmt.Print(client.SetSocialInfo(context.Background(), value0, value1, value2))
    fmt.Print("\n")
    break
  case "removeSocialInfo":
    if flag.NArg() - 1 != 3 {
      fmt.Fprintln(os.Stderr, "RemoveSocialInfo requires 3 args")
      flag.Usage()
    }
    argvalue0, err65 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err65 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    argvalue1 := flag.Arg(2)
    value1 := argvalue1
    arg67 := flag.Arg(3)
    mbTrans68 := thrift.NewTMemoryBufferLen(len(arg67))
    defer mbTrans68.Close()
    _, err69 := mbTrans68.WriteString(arg67)
    if err69 != nil {
      Usage()
      return
    }
    factory70 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt71 := factory70.GetProtocol(mbTrans68)
    argvalue2 := Profile.NewTSocialProfile()
    err72 := argvalue2.Read(jsProt71)
    if err72 != nil {
      Usage()
      return
    }
    value2 := argvalue2
    fmt.Print(client.RemoveSocialInfo(context.Background(), value0, value1, value2))
    fmt.Print("\n")
    break
  case "putData":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "PutData requires 2 args")
      flag.Usage()
    }
    argvalue0, err73 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err73 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    arg74 := flag.Arg(2)
    mbTrans75 := thrift.NewTMemoryBufferLen(len(arg74))
    defer mbTrans75.Close()
    _, err76 := mbTrans75.WriteString(arg74)
    if err76 != nil {
      Usage()
      return
    }
    factory77 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt78 := factory77.GetProtocol(mbTrans75)
    argvalue1 := Profile.NewTPlatformProfile()
    err79 := argvalue1.Read(jsProt78)
    if err79 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.PutData(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "getData":
    if flag.NArg() - 1 != 1 {
      fmt.Fprintln(os.Stderr, "GetData requires 1 args")
      flag.Usage()
    }
    argvalue0, err80 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err80 != nil {
      Usage()
      return
    }
    value0 := Profile.TKey(argvalue0)
    fmt.Print(client.GetData(context.Background(), value0))
    fmt.Print("\n")
    break
  case "":
    Usage()
    break
  default:
    fmt.Fprintln(os.Stderr, "Invalid function ", cmd)
  }
}
