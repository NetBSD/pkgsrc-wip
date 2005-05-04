# New ports collection makefile for:	freevrrpd
# Date created:				Tue Jan 29 18:44:25 EST 2002
# Whom:					Sebastien Petit <spe@bsdfr.org>
#
# $FreeBSD: ports/net/freevrrpd/Makefile,v 1.16 2004/05/26 22:20:17 pav Exp $
#

PORTNAME=	freevrrpd
DISTNAME=	freevrrpd-0.9.1
CATEGORIES=	net
PKGREVISION=	1
MASTER_SITES=	http://www.b0l.org/download/

MAINTAINER=	spe@b0l.org
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
