# $NetBSD: Makefile,v 1.1.1.1 2003/05/23 17:04:29 xtraeme Exp $
#

DISTNAME=	linuxsms-0.63
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxsms/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://linuxsms.sourceforge.net/
COMMENT=	Script in Perl for send short messages to gsm phones

USE_BUILDLINK2=		yes
USE_PERL5=		build
NO_BUILD=		yes

REPLACE_PERL=		${WRKSRC}/linuxsms

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/linuxsms
	${INSTALL_MAN} ${WRKSRC}/linuxsms.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/linuxsms ${PREFIX}/bin/linuxsms.pl
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/share/doc/linuxsms

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
