# $NetBSD: Makefile,v 1.3 2012/09/24 16:47:36 asau Exp $
#

DISTNAME=		mod_choke-0.06
PKGNAME=		${DISTNAME:S/mod_/ap-/}
CATEGORIES=		www
MASTER_SITES=		http://os.cyberheatinc.com/mod_choke/

MAINTAINER=		dmb@except.one.pl
HOMEPAGE=		http://os.cyberheatinc.com/mod_choke.php
COMMENT=		Limit resource usage by greedy clients

APACHE_MODULE_NAME=	mod_choke.so

.include "../../www/apache/module.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mod_choke && \
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mod_choke

.include "../../mk/bsd.pkg.mk"
