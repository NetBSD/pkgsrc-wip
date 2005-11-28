# $NetBSD: Makefile,v 1.6 2005/11/28 00:27:28 rillig Exp $

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

USE_TOOLS+=		gmake
MAKE_ENV+=		ROOT=${PREFIX:Q} ROOT_GROUP=${ROOT_GROUP:Q} \
			ROOT_USER=${ROOT_USER:Q}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sysvinit

.include "../../mk/bsd.pkg.mk"
