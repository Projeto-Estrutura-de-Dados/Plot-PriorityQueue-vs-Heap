heap <- read.csv("C:/Users/Julyana/Documents/P-c/Plot-PriorityQueue-vs-Heap/heap/heapFile.txt")
queue <- read.csv("C:/Users/Julyana/Documents/P-c/Plot-PriorityQueue-vs-Heap/priorityQueue/queueFile.txt")

heap <- heap[order(heap$num, decreasing = FALSE),]
queue <- queue[order(queue$num, decreasing = FALSE),]

plot(queue$num, queue$cont, type="o", col="blue", ann = FALSE, lwd = 5, pch = 20)
lines(heap$num, heap$cont, type="o", col="red", lwd = 5, pch = 20)

title(main="Heap vs Priority Queue", col.main="red", font.main=4)
title(xlab="Numero Inserido", col.lab=rgb(0,0.5,0))
title(ylab="Quantidade de comparações", col.lab=rgb(0,0.5,0))

legend("topright", c("Priority Queue","Heap"), cex=0.7, 
       col=c("blue","red"), pch=20, lty=1 ) 
legend("topleft", c("Max Queue","Max Heap", "Min Queue",
                    "Min Heap", max(queue$cont), max(heap$cont),
                    min(queue$cont), min(heap$cont)),
       cex=0.7, ncol = 2)