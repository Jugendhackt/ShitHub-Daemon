# ShitHub-Daemon
Background daemon for ShitHub (jugendhackt/shithub)

[![Build Status](https://travis-ci.org/Jugendhackt/ShitHub-Daemon.svg?branch=master)](https://travis-ci.org/Jugendhackt/ShitHub-Daemon)

### Protocol specifications
The ShitHub-Daemon uses UNIX domain sockets (IPC socket) to communicate with the PHP backend.
We will provide a separate PHP package for communication with this daemon. 

We are using XML, but still need to choose a xml-parser. TinyXML-2 would be a possibility.

#### Protocol - Header
```XML
<?xml version="1.1" encoding="UTF-8" standalone="yes" ?>
<ShitHubXML version="0.1">
    <Header>
        <Type>snippet_analysis</Type>
        <Analysis-Type>vulnerabilities</Analysis-Type>
        <Snippet-ID>42935</Snippet-ID>
        <Language>C++</Language>
    </Header>
</ShitHubXML>
```

**\<ShitHubXML\>** is the root element. The parameter version represents the ShitHub XML 
Protocol version.

**\<Header\>** is the start of the header. The header contains all important information's about the following XML.

**\<Type\>** is the type of the request. Currently supported: snippet_analysis

**\<Analysis-Type\>** (only if Type = snippet_analysis) represents what to analyse. Current supported: vulnerabilities

**\<Snippet-ID\>** (only if Type = snippet_analysis) is the id of the following snippet

**\<Language\>** (only if Type = snippet_analysis) is the programming language of following snippet

#### Protocol - Main
```XML
<?xml version="1.1" encoding="UTF-8" standalone="yes" ?>
<ShitHubXML version="0.1">
    <Header>
        ... (see above)
    </Header>
    <Main>
        <Snippet>
            Snippet code comes here.
        </Snippet>
    </Main>
</ShitHubXML>
```

**\<Snippet\>** (only if Type = snippet_analysis) contains the snippet's code
