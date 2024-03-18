set ns [new Simulator]
set nd [open 3.tr w]
set nf [open 3.nam w]
$ns trace-all $nd
$ns namtrace-all $nf

proc finish { } {
    global ns nd nf
    $ns flush-trace
    close $nf
    close $nd  
    exec nam 3.nam &  
    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 250Kb 10ms DropTail

#protocol layer
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set sink0 [new Agent/Null]
$ns attach-agent $n3 $sink0

set tcp0 [new Agent/TCP]
$ns attach-agent $n1 $tcp0
set sink1 [new Agent/TCPSink]
$ns attach-agent $n3 $sink1

$ns connect $udp0 $sink0
$ns connect $tcp0 $sink1

#application layer
set cbr0 [new Application/Traffic/CBR]
set ftp0 [new Application/FTP]

$cbr0 attach-agent $udp0
$ftp0 attach-agent $tcp0

$ns at 0.5 "$cbr0 start"
$ns at 0.5 "$ftp0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 4.5 "$ftp0 stop"
$ns at 5.0 "finish"
$ns run