# $NetBSD: Makefile,v 1.2 2003/09/19 21:31:38 thomasklausner Exp $
#

DISTNAME=	pdb2ldif-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.uslinux.net/software/packages/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.uslinux.net/software/pkginfo.php?pkg=pdb2ldif
COMMENT=	Converts Palm Address Book PDB files into an LDAP-usable LDIF file

DEPENDS+=	p5-Palm>=1.3.0:../../devel/p5-Palm

NO_BUILD=	YES
USE_BUILDLINK2=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdb2ldif ${PREFIX}/bin/pdb2ldif

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
