# $NetBSD: Makefile,v 1.1.1.1 2003/05/08 05:07:53 jeremy-c-reed Exp $

DISTNAME=		sysvinit-2.84
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		sysutils
# XXX sunsite still has older version
# XXX MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/daemons/init/}
MASTER_SITES=		ftp://ftp.cistron.nl/pub/people/miquels/sysvinit/

MAINTAINER=		packages@netbsd.org
#HOMEPAGE
COMMENT=		The Linux System V init and miscellaneous Linux tools

# this uses linux/kd.h for example
ONLY_FOR_PLATFORM=	Linux-*-*	# This is the Linux init

USE_GMAKE=		YES
MAKE_ENV+=		ROOT=${PREFIX} ROOT_GROUP=${ROOT_GROUP} \
			ROOT_USER=${ROOT_USER}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sysvinit

.include "../../mk/bsd.pkg.mk"
