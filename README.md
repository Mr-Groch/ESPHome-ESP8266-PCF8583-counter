# ESPHome-ESP8266-PCF8583-counter
Battery impulse counter based on ESPHome with ESP8266 and PCF8583 acting as hardware counter

Example configuration for energy meter with 6400 impulses per kWh. You can change that in yaml:

```yaml
                return (1000.0 * (delta_count / 6400.0) * (3600.0 / 60.0));
```
```yaml
              state: !lambda return (x / 6400.0);
```

![ESP8266_PCF8583_counter](https://user-images.githubusercontent.com/20594810/114005030-765c2f00-985f-11eb-8706-b02e513d68be.png)

![IMG_20210407_204011](https://user-images.githubusercontent.com/20594810/114005077-81af5a80-985f-11eb-9b20-af6c726cf532.jpg)

![image](https://user-images.githubusercontent.com/20594810/114075546-ef7e7500-98a5-11eb-96bc-c3697e90aff7.png)

![image](https://user-images.githubusercontent.com/20594810/114076466-fce82f00-98a6-11eb-93a7-83f3eef7e40d.png)
