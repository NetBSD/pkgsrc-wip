# $NetBSD: Makefile,v 1.2 2011/10/15 18:10:37 jgoamakf Exp $
#

DISTNAME=	XML-DT-0.56
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/XML-DT/
COMMENT=	Perl module for down translation of XML files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-DTDParser>=2.0:../../wip/p5-XML-DTDParser
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/XML/DT/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
