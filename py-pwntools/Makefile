# $NetBSD$

DISTNAME=	pwntools-4.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pwntools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pwntools.com/
COMMENT=	CTF framework and exploit development library
LICENSE=	gnu-gpl-v3 AND 2-clause-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-capstone>=3.0.5:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-colored-traceback-[0-9]*:../../wip/py-colored-traceback
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-intervaltree>=3.0:../../devel/py-intervaltree
DEPENDS+=	${PYPKGPREFIX}-mako>=1.0.0:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.15.2:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-psutil>=3.3.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pyelftools>=0.2.4:../../devel/py-pyelftools
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ropgadget>=5.3:../../wip/py-ropgadget
DEPENDS+=	${PYPKGPREFIX}-rpyc-[0-9]*:../../net/py-rpyc
DEPENDS+=	${PYPKGPREFIX}-serial>=2.7:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers-[0-9]*:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-unicorn>=1.0.2:../../emulators/py-unicorn

PYTHON_VERSIONED_DEPENDENCIES+=	packaging pip

post-install:
.for f in asm checksec common constgrep cyclic debug disablenx disasm elfdiff \
    elfpatch errno hex main phd pwnstrip scramble shellcraft template unhex \
    update version
	${RM} ${DESTDIR}${PREFIX}/bin/${f}
.endfor
	${MV} ${DESTDIR}${PREFIX}/bin/pwn ${DESTDIR}${PREFIX}/bin/pwn${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/pwntools-doc ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
