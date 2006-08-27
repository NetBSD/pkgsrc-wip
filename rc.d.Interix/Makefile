# $NetBSD: Makefile,v 1.1 2006/08/27 12:03:07 cheusov Exp $
#

DISTNAME=		rc.d.Interix-0.0.1
CATEGORIES=		pkgtools sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		#none
COMMENT=		NetBSD rc.d system for MS Interix

#ONLY_FOR_PLATFORM=	Interix-*-*
#DEPENDS+=		rcorder-[0-9]*:../../pkgtools/rcorder
#DEPENDS+=		rc.subr-[0-9]*:../../pkgtools/rc.subr

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

FILES_SUBST+=		PKGSRC_PREFIX=${PREFIX}
MESSAGE_SUBST+=		PKGSRC_PREFIX=${PREFIX}

do-install:
	${INSTALL_SCRIPT} ${.CURDIR}/files/pkgsrc_rc ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
