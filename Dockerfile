FROM openjdk:23
VOLUME /tmp
EXPOSE 8080
ARG JAR_FILE=target/libreria-web-0.0.1-SNAPSHOT.jar
ADD ${JAR_FILE} app.jar
RUN mkdir /root/aplicacion
COPY lib/libeval.so /lib64
COPY lib/libstr.so /lib64
COPY lib/cjson/* /lib64
COPY libevaluador/libevaluador.so /lib64
ENV LD_LIBRARY_PATH=/usr/local/lib/jni:/lib64:$LD_LIBRARY_PATH
ENTRYPOINT ["java","-jar","/app.jar"]
