# $NetBSD: Makefile,v 1.1 2015/06/28 01:33:35 mbowie Exp $

DISTNAME=	portfwd-0.29
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=portfwd/}

MAINTAINER=	mbowie@buzmo.com
HOMEPAGE=	http://portfwd.sourceforge.net/
COMMENT=	Port Forwarding Daemon
LICENSE=	gnu-gpl-v1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

RCD_SCRIPTS=		${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/single.cfg ${PKG_SYSCONFDIR}/${PKGBASE}.conf
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${DOCDIR}

COREDOCS=	COPYING CREDITS README TODO
DOCS=		FAQ conf.txt
EGFILES=	alias.cfg bind-new.cfg bind.cfg chain.cfg debug_ftp.cfg \
		dns.cfg empty.cfg external-director.cfg fragile.cfg \
		ftp.cfg load-balance.cfg mail.cfg portfwd1.cfg portfwd2.cfg \
		single.cfg test.cfg udp.cfg x.cfg

post-install:
.for doc in ${COREDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${DOCDIR}
.endfor
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DESTDIR}${DOCDIR}
.endfor
.for egfile in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/cfg/${egfile} ${DESTDIR}${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
