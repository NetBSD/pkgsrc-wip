# New ports collection makefile for:	freevrrpd
# Date created:				Tue Jan 29 18:44:25 EST 2002
# Whom:					Sebastien Petit <spe@phear.org>
#
# $Id: Makefile,v 1.2 2005/05/27 11:30:08 spetit Exp $
#

PORTNAME=	freevrrpd
DISTNAME=	freevrrpd-0.9.1
CATEGORIES=	net
PKGREVISION=	1
MASTER_SITES=	http://bmw2002.hexod.net/opensource/

MAINTAINER=	spe@phear.org
COMMENT=	This a VRRP RFC2338 Compliant implementation under FreeBSD

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

USE_PKGINSTALL= yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample ${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/freevrrpd.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8


.include "../../mk/bsd.pkg.mk"
