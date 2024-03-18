BEGIN{
    count_tcp = 0;
    count_udp = 0;
}
{
    pkt = $5
    if(pkt == "cbr"){
        count_udp++;
    }
    if(pkt == "tcp"){
        count_tcp++;
    }
}
END{
    printf("No of packets in tcp %d\n", count_tcp);
    printf("No of packets in udp %d\n", count_udp);
    
}