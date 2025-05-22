#!/bin/bash
echo "Starting jobs"
sleep 3 &
sleep 5 &
wait
echo "All jobs done"
