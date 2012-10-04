# $NetBSD: Makefile,v 1.2 2012/10/04 19:12:08 asau Exp $
#

DISTNAME=	postfix-policyd-spf-perl-2.007
PKGNAME=	p5-policyd-spf-2.007
CATEGORIES=	mail
MASTER_SITES=	http://launchpad.net/postfix-policyd-spf-perl/trunk/2.007/+download/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://launchpad.net/postfix-policyd-spf-perl/
COMMENT=	Basic Postfix policy engine for SPF checking
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Mail-SPF:../../mail/p5-Mail-SPF
DEPENDS+=	p5-NetAddr-IP:../../net/p5-NetAddr-IP
REPLACE_PERL=	postfix-policyd-spf-perl
INSTALLATION_DIRS=	libexec

USE_LANGUAGES=	# none
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postfix-policyd-spf-perl ${DESTDIR}/${PREFIX}/libexec/postfix-policyd-spf-perl

.include "../../mk/bsd.pkg.mk"
