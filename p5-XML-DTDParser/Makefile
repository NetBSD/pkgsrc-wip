# $NetBSD: Makefile,v 1.2 2011/10/15 17:00:56 jgoamakf Exp $
#

DISTNAME=	XML-DTDParser-2.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/XML-DTDParser/
COMMENT=	Perl module for handling XML DTDs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/XML/DTDParser/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
