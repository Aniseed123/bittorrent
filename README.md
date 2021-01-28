# bittorrent
A simulation of how Bit Torrent, the popular P2P supported file sharing algorithm, works. The simulation is executed in C++.

Standard peer-to-peer file sharing networks consist of
“seeds” and “peers”. The “seeds” are the users that possess the
file in question and seed this file to those looking to obtain
said file, called “peers”. When downloading a file on a P2P
network, the peer connects to several seeds and begins
acquiring packets of the file from these seeds. As the
downloading progresses, the peer too is able to begin seeding
its downloaded packets to other peers in the network. In this
manner P2P networks are self sufficient and dictated by the
users. Our project emulated this behavior of P2P networks.
