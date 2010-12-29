# $NetBSD: Makefile,v 1.5 2010/12/29 13:24:37 ftigeot Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
#

DISTNAME=	fop-${VERSION}-bin
PKGNAME=	fop-${VERSION}
VERSION=	1.0
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_APACHE:=xmlgraphics/fop/binaries/}

HOMEPAGE=	http://xmlgraphics.apache.org/fop/
COMMENT=	Print formatter driven by XSL Formatting Objects (XSL-FO)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
INSTALLATION_DIRS=	bin share/java/fop

.include "../../mk/bsd.prefs.mk"

WRKSRC=${WRKDIR}/${PKGNAME}

.include "options.mk"

PLIST_SRC=	${PKGDIR}/PLIST

.if !empty(PKG_OPTIONS:Mfop-docs)
PLIST_SRC+=	${PKGDIR}/PLIST.docs
.endif

post-extract:
.if empty(PKG_OPTIONS:Mfop-docs)
.for subdir in docs javadocs
	cd ${WRKSRC} && ${RM} -rf ${subdir}
.endfor
.endif

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/java/fop
	${LN} -sf ../share/java/fop/fop ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
