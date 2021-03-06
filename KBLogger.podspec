Pod::Spec.new do |spec|
	spec.name                 = 'KBLogger'
	spec.version              = '1.0.1'
	spec.license              = { :type => 'MIT' }
	spec.homepage             = "https://github.com/byss/#{spec.name}"
	spec.authors              = { 'Kirill byss Bystrov' => 'kirrbyss@gmail.com' }
	spec.summary              = 'Simple logging proxy (logging to NSLog by default).'
	spec.source               = { :git => "#{spec.homepage}.git", :tag => "v#{spec.version}" }
	spec.requires_arc         = true
	spec.source_files         = "#{spec.name}.{h,m}"

	spec.ios.deployment_target     = '4.0'
	spec.osx.deployment_target     = '10.6'
	spec.watchos.deployment_target = '2.0'
	spec.tvos.deployment_target    = '9.0'
end
