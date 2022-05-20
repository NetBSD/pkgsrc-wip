# $NetBSD$
PKG_OPTIONS_VAR=	PKG_OPTIONS.libnfc
PKG_SUPPORTED_OPTIONS=	pcsc acr122pcsc acr122usb acr122s arygon pn532uart pn53xusb doc
PKG_SUGGESTED_OPTIONS=	acr122usb acr122s arygon pn532uart pn53xusb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc)
PCSC_DRIVER=	acr122_pcsc,
.include "../../security/pcsc-lite/buildlink3.mk"
.else
PCSC_DRIVER=
.endif

.if !empty(PKG_OPTIONS:Macr122pcsc)
ACR122_PCSC_DRIVER=	acr122_pcsc,
.include "../../security/pcsc-lite/buildlink3.mk"
.else
ACR122_PCSC_DRIVER=
.endif

.if !empty(PKG_OPTIONS:Macr122usb)
ACR122_USB_DRIVER=	acr122_usb,
.include "../../mk/libusb.buildlink3.mk"
.else
ACR122_USB_DRIVER=
.endif

.if !empty(PKG_OPTIONS:Macr122s)
ACR122S_DRIVER=	acr122s,
.else
ACR122S_DRIVER=
.endif

.if !empty(PKG_OPTIONS:Marygon)
ARYGON_DRIVER=	arygon,
.else
ARYGON_DRIVER=
.endif

.if !empty(PKG_OPTIONS:Mpn532uart)
PN532_UART_DRIVER=	pn532_uart,
.else
PN532_UART_DRIVER=
.endif

.if !empty(PKG_OPTIONS:Mpn53xusb)
PN53X_USB_DRIVER=	pn53x_usb,
.include "../../mk/libusb.buildlink3.mk"
.else
PN53X_USB_DRIVER=
.endif

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-doc
BUILD_DEPENDS+=		doxygen>=1.8.11:../../devel/doxygen
.endif

CONFIGURE_ARGS+=	--with-drivers="${PCSC_DRIVER}${ACR122_PCSC_DRIVER}${ACR122_USB_DRIVER}${ACR122S_DRIVER}${ARYGON_DRIVER}${PN532_I2C_DRIVER}${PN532_SPI_DRIVER}${PN532_UART_DRIVER}${PN53X_USB_DRIVER}"
