# $NetBSD: Makefile,v 1.6 2012/10/07 14:09:36 asau Exp $
#

DISTNAME=		rc.d.Interix-0.0.1
CATEGORIES=		pkgtools sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		#none
COMMENT=		NetBSD rc.d system for MS Interix

ONLY_FOR_PLATFORM=	Interix-*-*
DEPENDS+=		rcorder-[0-9]*:../../pkgtools/rcorder
DEPENDS+=		rc.subr-[0-9]*:../../pkgtools/rc.subr

NO_CHECKSUM=		yes
NO_BUILD=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

FILES_SUBST+=		PKGSRC_PREFIX=${PREFIX}
MESSAGE_SUBST+=		PKGSRC_PREFIX=${PREFIX}

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_SCRIPT} ${.CURDIR}/files/pkgsrc_rc ${DESTDIR}${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
