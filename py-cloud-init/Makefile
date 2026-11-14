# $NetBSD$

DISTNAME=	cloud-init-26.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/cloud-init/trunk/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cloud-init.io/
COMMENT=	Industry-standard cloud instance initialization
LICENSE=	gnu-gpl-v3 OR apache-2.0

#TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-oauthlib-[0-9]*:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonpatch-[0-9]*:../../textproc/py-jsonpatch
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.10.4:../../net/py-netifaces

TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib

MESON_ARGS+=	-Dinit_system=sysvinit_netbsd
MESON_ARGS+=	-Dbash_completion=false
# We can't install wrong system templates if we don't install any
# system templates.
# MESON_ARGS+=	-Ddistro_templates=chef_client.rb.tmpl,resolv.conf.tmpl,timesyncd.conf.tmpl
MESON_ARGS+=	-Ddisable_sshd_keygen=true
MESON_ARGS+=	-Ddownstream_version=${PKGVERSION}

REPLACE_PYTHON=	scripts/cloud-id scripts/cloud-init

post-install:
	${FIND} ${DESTDIR}${INSTDIR} -name '*.orig' | ${XARGS} ${RM} -f

.include "../../devel/meson/build.mk"
PYTHON_FOR_BUILD_ONLY=	no
.include "../../lang/python/tool.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
