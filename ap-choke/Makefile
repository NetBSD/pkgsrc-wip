# $NetBSD: Makefile,v 1.1.1.1 2005/03/16 00:57:54 dmb_ Exp $
#

DISTNAME=		mod_choke-0.06
PKGNAME=		${DISTNAME:S/mod_/ap-/}
CATEGORIES=		www
MASTER_SITES=		http://os.cyberheatinc.com/mod_choke/

MAINTAINER=		dmb@except.one.pl
HOMEPAGE=		http://os.cyberheatinc.com/mod_choke.php
COMMENT=		Limit resource usage by greedy clients

USE_BUILDLINK3=		yes

APACHE_MODULE_NAME=	mod_choke.so

.include "../../www/apache/module.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_choke && \
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_choke

.include "../../mk/bsd.pkg.mk"
