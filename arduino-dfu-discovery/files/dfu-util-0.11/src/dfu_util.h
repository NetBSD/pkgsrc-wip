#ifndef DFU_UTIL_H
#define DFU_UTIL_H

/* USB string descriptor should contain max 126 UTF-16 characters
 * but 254 would even accommodate a UTF-8 encoding + NUL terminator */
#define MAX_DESC_STR_LEN 254

enum mode {
	MODE_NONE,
	MODE_VERSION,
	MODE_LIST,
	MODE_DETACH,
	MODE_UPLOAD,
	MODE_DOWNLOAD
};

extern struct dfu_if *dfu_root;
extern char *match_path;
extern int match_vendor;
extern int match_product;
extern int match_vendor_dfu;
extern int match_product_dfu;
extern int match_config_index;
extern int match_iface_index;
extern int match_iface_alt_index;
extern int match_devnum;
extern const char *match_iface_alt_name;
extern const char *match_serial;
extern const char *match_serial_dfu;

void probe_devices(libusb_context *);
void disconnect_devices(void);
void print_dfu_if(struct dfu_if *);
void list_dfu_interfaces(void);

#endif /* DFU_UTIL_H */
