// usb_ffbwheel.h
#ifndef _USB_FFBWHEEL_H_
#define _USB_FFBWHEEL_H_
 
#if defined(USB_FFBWHEEL)

#include <inttypes.h>
 
// C language implementation
#ifdef __cplusplus
extern "C" {
#endif
int usb_ffbwheel_send(void);
// we have packets that are 2 byte long // ..was 6 bytes
extern uint8_t usb_ffbwheel_data[2];
#ifdef __cplusplus
}
#endif
 
// C++ interface
#ifdef __cplusplus
class usb_ffbwheel_class
{
private:
	static uint8_t auto_send;
 
public:
 
	void SetSteeringPosition(uint16_t val) {
		/*if(val > 16383) 
			usb_ffbwheel_data[axis] = 16383;
		else if (val < 0) 
			usb_ffbwheel_data[axis] = 0;
		else 
			usb_ffbwheel_data[axis] = val;
		*/

		usb_ffbwheel_data[0] = val & 255; //lowest byte first
		usb_ffbwheel_data[1] = val >> 8; //the remaining byte

		if(auto_send) 
			usb_ffbwheel_send();
	}
 
	void SetAutoSend(bool send) {
		auto_send = send;
	}
 
	void Send() {
		usb_ffbwheel_send();
	}
};
extern usb_ffbwheel_class FFBWheel;
 
#endif // __cplusplus
#endif // USB_FFBWHEEL
#endif // _USB_FFBWHEEL_H_