# $NetBSD: options.mk,v 1.2 2011/01/12 10:05:46 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fop
PKG_SUPPORTED_OPTIONS=	fop-docs

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfop-docs)
PLIST_SRC+=	${PKGDIR}/PLIST.docs
.endif

post-extract:
.if empty(PKG_OPTIONS:Mfop-docs)
.for subdir in docs javadocs
	cd ${WRKSRC} && ${RM} -rf ${subdir}
.endfor
.endif
