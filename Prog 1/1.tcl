set ns [new Simulator]
set nd [open 1.tr w]
set nf [open 1.nam w]
$ns trace-all $nd
$ns namtrace-all $nf

proc finish { } {
    global ns nd nf
    $ns flush-trace
    close $nd
    close $nf
    exec nam 1.nam &
    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 200Kb 10ms DropTail
$ns queue-limit $n1 $n2 5

#protocol layer: we join via this
set udp0 [new Agent/UDP]
set sink0 [new Agent/Null]
$ns attach-agent $n0 $udp0
$ns attach-agent $n2 $sink0
$ns connect $udp0 $sink0

#application layer
set cbr0 [new Application/Traffic/CBR]

#connect cbr to protocol layer
$cbr0 attach-agent $udp0

$ns at 0.2 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"

$ns run