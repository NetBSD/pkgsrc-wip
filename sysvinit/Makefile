# $NetBSD: Makefile,v 1.4 2004/01/25 02:33:44 grantbeattie Exp $

DISTNAME=		sysvinit-2.84
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		sysutils
# XXX sunsite still has older version
# XXX MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/daemons/init/}
MASTER_SITES=		ftp://ftp.cistron.nl/pub/people/miquels/sysvinit/

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE
COMMENT=		The Linux System V init and miscellaneous Linux tools

# this uses linux/kd.h for example
ONLY_FOR_PLATFORM=	Linux-*-*	# This is the Linux init

USE_GNU_TOOLS+=		make
MAKE_ENV+=		ROOT=${PREFIX} ROOT_GROUP=${ROOT_GROUP} \
			ROOT_USER=${ROOT_USER}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sysvinit

.include "../../mk/bsd.pkg.mk"
