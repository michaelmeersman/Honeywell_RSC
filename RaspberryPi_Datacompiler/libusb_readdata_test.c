#include <stdio.h>
#include <libusb-1.0/libusb.h>

/*
 Compile with -  gcc libusb_readdata_test.c -o libusb_readdata_test -lusb-1.0 -std=c11
*/

#define VENDOR_ID 0x062a
#define PRODUCT_ID 0x5918

int main() {

	//initialize libusb
	int initReturn = libusb_init(NULL);

	if(initReturn < 0) {
		printf("libusb initialization error!\n");
		return 1;
	}

	//find device
	static struct libusb_device_handle *usbDevice = NULL;
	usbDevice = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID);

	if(!usbDevice) {
		printf("Cannot find device!\n");
		return 1;
	}

	libusb_detach_kernel_driver(usbDevice, 0);
	
	initReturn = libusb_set_configuration(usbDevice, 1);

	if(initReturn < 0) {
		printf("Set configuration error!\n");
		return 1;
	}

	initReturn = libusb_claim_interface(usbDevice, 0);

	if(initReturn < 0) {
		printf("Claim interface error!\n");
		return 1;
	}

	unsigned char data[1024]="\0";
	int size;

	while(1) {
    //read data :*
		int ret = libusb_bulk_transfer(usbDevice,0x81,data,0x0008,&size,1000);
		for(int i=0; i<size; i++) {
			printf("%02x ", (unsigned char)(data[i]));
		}

		printf("\n");
	}

	libusb_release_interface(usbDevice, 0);
	libusb_close(usbDevice);
	libusb_exit(NULL);
	
	return 0;
}