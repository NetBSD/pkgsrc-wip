# $NetBSD: Makefile,v 1.9 2013/08/22 08:50:06 obache Exp $
#

DISTNAME=	Mailer-0.1.6
PKGNAME=	deforaos-mailer-0.1.6
CATEGORIES=	mail
MASTER_SITES=	https://www.defora.org/os/download/download/4029/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop e-mail client

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/compose.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/compose.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/mailer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mailer.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
