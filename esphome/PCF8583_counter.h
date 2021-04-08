#include "esphome.h"
#include "PCF8583.h"

class PCF8583Counter : public PollingComponent, public Sensor {
 public:
  // declare an instance of the library for IC at provided in constructor address
  // (0xA0 - A0 pin connected to ground)
  // (0xA2 - A0 pin connected to vdd)
  PCF8583 counter;

  // constructor
  PCF8583Counter(uint32_t update_interval, uint8_t address) : PollingComponent(update_interval), counter(address) {}

  float get_setup_priority() const override { return esphome::setup_priority::DATA; }

  void setup() override {
    // This will be called by App.setup()
    // configure PCF8586 to event counter mode and reset counts
    counter.setMode(MODE_EVENT_COUNTER);
	// We want to use it in deep sleep mode, so don't reset counter on each boot
    //counter.setCount(0);
  }

  void update() override {
    // This will be called every "update_interval" milliseconds.
    uint32_t count = counter.getCount();
    ESP_LOGD("custom", "PCF8583 retrieved counter: %i", count);
    publish_state(count);
  }

};