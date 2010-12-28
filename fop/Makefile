# $NetBSD: Makefile,v 1.3 2010/12/28 20:04:00 ftigeot Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
#

DISTNAME=	fop-${VERSION}-bin
PKGNAME=	fop-${VERSION}
VERSION=	1.0
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_APACHE:=xmlgraphics/fop/binaries/}
EXTRACT_SUFX=	.tar.gz

HOMEPAGE=	http://xmlgraphics.apache.org/fop/
COMMENT=	Print formatter driven by XSL Formatting Objects (XSL-FO)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
INSTALLATION_DIRS=	share/java/fop

.include "../../mk/bsd.prefs.mk"

WRKSRC=${WRKDIR}/${PKGNAME}

.include "options.mk"

PLIST_SRC=	${PKGDIR}/PLIST

.if !empty(PKG_OPTIONS:Mfop-docs)
PLIST_SRC+=	${PKGDIR}/PLIST.docs
.endif

post-extract:
.if empty(PKG_OPTIONS:Mfop-docs)
.for _dir in docs javadocs
	cd ${WRKSRC} && ${RM} -rf ${_dir}
.endfor
.endif

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/java/fop
	${LN} -sf ${DESTDIR}${PREFIX}/share/java/fop/fop ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
