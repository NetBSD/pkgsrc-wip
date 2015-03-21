# $NetBSD: options.mk,v 1.7 2015/03/21 01:00:09 makoto Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.adobe-flash-plugin
PKG_SUPPORTED_OPTIONS=	nspluginwrapper pulseaudio

# XXXX: If nspluginwrapper is enabled and this package is installed after
# firefox (or similar) it will install a system wide wrapped plugin into
# @PREFIX/lib/<browser>/plugins. If it is installed before a browser
# it will install a plugin for the current user in ~/.mozilla/plugins/
# or similar. This is inconsistant and potentially confusing.

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUGGESTED_OPTIONS=	nspluginwrapper
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnspluginwrapper)
DEPENDS+= nspluginwrapper>=1.4.4:../../wip/nspluginwrapper
.  if !empty(PKG_OPTIONS:Mpulseaudio)
EMUL_MODULES.linux+=	pulseaudio
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pulseaudio
.  else
DEPENDS+= libflashsupport>0:../../multimedia/libflashsupport
.  endif
INSTALL_TEMPLATES+=	${PKGDIR}/INSTALL.nspluginwrapper
DEINSTALL_TEMPLATES+=	${PKGDIR}/INSTALL.nspluginwrapper
.endif
