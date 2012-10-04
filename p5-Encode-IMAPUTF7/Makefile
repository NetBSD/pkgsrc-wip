# $NetBSD: Makefile,v 1.4 2012/10/04 10:45:26 asau Exp $

DISTNAME=	Encode-IMAPUTF7-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Encode-IMAPUTF7/
COMMENT=	Modified UTF7 encoding (for IMAP)

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Encode/IMAPUTF7/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
