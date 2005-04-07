# $NetBSD: Makefile,v 1.6 2005/04/07 01:13:13 rillig Exp $
#

DISTNAME=	AxKit-1.6.2
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5axk
WRKSRC=         ${WRKDIR}/AxKit-1.62
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://axkit.org/
COMMENT=	AxKit is an XML Application Server for Apache

DEPENDS+=	p5-Compress-Zlib>=1.21:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Digest-MD5>=2.09:../../security/p5-Digest-MD5
DEPENDS+=	p5-Error>=0.14:../../devel/p5-Error
DEPENDS+=	p5-libapreq>=0.32:../../www/p5-libapreq
DEPENDS+=	p5-File-Spec>=0.82:../../devel/p5-File-Spec
DEPENDS+=	p5-Apache-Test>=1.00:../../www/p5-Apache-Test
DEPENDS+=	p5-XML-Parser>=2.27:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-XPath>=1.00:../../textproc/p5-XML-XPath
DEPENDS+=	p5-XML-LibXML>=1.51:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-LibXSLT>=1.49:../../textproc/p5-XML-LibXSLT
DEPENDS+=	p5-XML-Sablotron>=0.40:../../textproc/p5-XML-Sablotron
DEPENDS+=	p5-Perl-Tidy>=20031021:../../devel/p5-Perl-Tidy

.include "../../lang/perl5/module.mk"

.include "../../textproc/libxml2/buildlink3.mk"
DEPENDS+=	${BUILDLINK_DEPENDS.libxml2}

.include "../../www/ap-perl/buildlink3.mk"
DEPENDS+=	${BUILDLINK_DEPENDS.ap-perl}

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/AxKit/.packlist

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
