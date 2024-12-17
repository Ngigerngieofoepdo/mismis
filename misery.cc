repeat wait() until game:IsLoaded() wait()
game:GetService("Players").LocalPlayer.Idled:connect(function()
game:GetService("VirtualUser"):ClickButton2(Vector2.new())
end)

--[[
    @misery.cc
]]

-- // Fixed By 1of1.al (real)

--[[
    @misery.cc
]]
-- // Variables
local ws, uis, rs, hs, cas, plrs, stats = game:GetService("Workspace"), game:GetService("UserInputService"), game:GetService("RunService"), game:GetService("HttpService"), game:GetService("ContextActionService"), game:GetService("Players"), game:GetService("Stats")
--
local playerlistIndividualTweak = nil
local pListMistToggle = nil
--
local aimviewerTargets = {}
--
local removeAimviewerTarget = function(target)
    local newta = {}
    for i,v in next, aimviewerTargets do
        if v[1] ~= target then
            table.insert(newta, v)
        end
    end
    aimviewerTargets = newta
end
--
local isAimviewerTarget = function(target)
    for _, v in next, aimviewerTargets do
        if v[1] == target then
            return true
        end
    end
    return false
end
--
local localplayer = plrs.LocalPlayer
--
local ResetMemoryCategory, SetMemoryCategory, SetUpvalueName, SetMetatable, ProfileBegin, GetMetatable, GetConstants, GetRegistry, GetUpvalues, GetConstant, SetConstant, GetUpvalue, ValidLevel, LoadModule, SetUpvalue, ProfileEnd, GetProtos, GetLocals, Traceback, SetStack, GetLocal, DumpHeap, GetProto, SetLocal, GetStack, GetFenv, GetInfo, Info = debug.resetmemorycategory, debug.setmemorycategory, debug.setupvaluename, debug.setmetatable, debug.profilebegin, debug.getmetatable, debug.getconstants, debug.getregistry, debug.getupvalues, debug.getconstant, debug.setconstant, debug.getupvalue, debug.validlevel, debug.loadmodule, debug.setupvalue, debug.profileend, debug.getprotos, debug.getlocals, debug.traceback, debug.setstack, debug.getlocal, debug.dumpheap, debug.getproto, debug.setlocal, debug.getstack, debug.getfenv, debug.getinfo, debug.info


--
local mouse = localplayer:GetMouse()
--
local Client = localplayer
--
local cZoom, MaxZoom, MinZoom = (workspace.CurrentCamera.CoordinateFrame.p - plrs.LocalPlayer.Character.Head.Position).magnitude, plrs.LocalPlayer.CameraMaxZoomDistance, plrs.LocalPlayer.CameraMinZoomDistance
local oMaxZoom, oMinZoom = MaxZoom, MinZoom
--
local LockScrolling = function()
    print("LOCK")
    cZoom, MaxZoom, MinZoom = (workspace.CurrentCamera.CoordinateFrame.p - plrs.LocalPlayer.Character.Head.Position).magnitude, plrs.LocalPlayer.CameraMaxZoomDistance, plrs.LocalPlayer.CameraMinZoomDistance
    plrs.LocalPlayer.CameraMaxZoomDistance = cZoom
    plrs.LocalPlayer.CameraMinZoomDistance = cZoom
end
local UnlockScrolling = function()
    print("Unlock")
    plrs.LocalPlayer.CameraMaxZoomDistance = oMaxZoom
    plrs.LocalPlayer.CameraMinZoomDistance = oMinZoom
end
--
local Remove = table.remove
local Unpack = table.unpack
local Find = table.find
local Clamp = math.clamp
-- UI Variables
if not isfolder("Tyrisware") then
    makefolder("Tyrisware")
end

if not isfolder("Tyrisware/Configs") then
    makefolder("Tyrisware/Configs")
end

if not isfolder("Tyrisware/Images") then
    makefolder("Tyrisware/Images")
end
local library = {
    drawings = {},
    objects = {},
    hidden = {},
    connections = {},
    pointers = {},
    began = {},
    ended = {},
    changed = {},
    colors = {},
    hovers = {},
    Relations = {},
    folders = {
        main = "Tyrisware",
        assets = "Tyrisware/Images",
        configs = "Tyrisware/Configs"
    },
    shared = {
        initialized = false,
        fps = 0,
        ping = 0
    }
}
--
local utility = {
    Keyboard = {
        Letters = {
            "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
        },
        Modifiers = {
            ["`"] = "~", ["1"] = "!", ["2"] = "@", ["3"] = "#", ["4"] = "$", ["5"] = "%", ["6"] = "^", ["7"] = "&", ["8"] = "*", ["9"] = "(",
            ["0"] = ")", ["-"] = "_", ["="] = "+", ["["] = "{", ["]"] = "}", ["\\"] = "|", [";"] = ":", ["'"] = '"', [","] = "<", ["."] = ".",
            ["/"] = "?"
        },
        InputNames = {
            One = "1", Two = "2", Three = "3", Four = "4", Five = "5", Six = "6", Seven = "7", Eight = "8", Nine = "9", Zero = "0",
            LeftBracket = "[", RightBracket = "]", Semicolon = ";", BackSlash = "\\", Slash = "/", Minus = "-", Equals = "=", Return = "Enter",
            Backquote = "`", CapsLock = "Caps", LeftShift = "LShift", RightShift = "RShift", LeftControl = "LCtrl", RightControl = "RCtrl",
            LeftAlt = "LAlt", RightAlt = "RAlt", Backspace = "Back", Plus = "+", PageUp = "PgUp", PageDown = "PgDown", Delete = "Del",
            Insert = "Ins", NumLock = "NumL", Comma = ",", Period = "."
        }
    }
}
local pages = {}
local sections = {}
-- Theme Variables
--local themes = {}
local theme = {
    accent = Color3.fromRGB(55, 175, 225),
    lightcontrast = Color3.fromRGB(30, 30, 30),
    darkcontrast = Color3.fromRGB(20, 20, 20),
    outline = Color3.fromRGB(0, 0, 0),
    inline = Color3.fromRGB(50, 50, 50),
    textcolor = Color3.fromRGB(255, 255, 255),
    textdark = Color3.fromRGB(175, 175, 175),
    textborder = Color3.fromRGB(0, 0, 0),
    cursoroutline = Color3.fromRGB(10, 10, 10),
    font = 2,
    textsize = 13
}




-- // utility Functions
do
    --
    
    --
    function utility:Size(xScale,xOffset,yScale,yOffset,instance)
        if instance then
            local x = xScale*instance.Size.x+xOffset
            local y = yScale*instance.Size.y+yOffset
            --
            return Vector2.new(x,y)
        else
            local vx,vy = ws.CurrentCamera.ViewportSize.x,ws.CurrentCamera.ViewportSize.y
            --
            local x = xScale*vx+xOffset
            local y = yScale*vy+yOffset
            --
            return Vector2.new(x,y)
        end
    end
    --
    function utility:GetClipboard()
        print("GETCLIPBOARD")
        repeat task.wait() until iswindowactive()
        task.wait()
        local Text = ""
        --
        local ScreenGui = Instance.new("ScreenGui", game.CoreGui)
        syn.protect_gui(ScreenGui)
        ScreenGui.Parent = game:GetService("CoreGui")
        --
        local TextBox = Instance.new("TextBox", game)
        TextBox.Size = UDim2.new(0, 0, 0, 0)
        TextBox.Position = UDim2.new(-999, 0, -999, 0)
        TextBox.Parent = ScreenGui
        TextBox.Text = ""
        --
        TextBox:CaptureFocus()
        --
        keypress(0x11)
        keypress(0x56) 
        task.wait()
        keyrelease(0x56)
        keyrelease(0x11)
        --
        if TextBox.Text == "" then
            TextBox:CaptureFocus()
            --
            task.wait()
            --
            keypress(0x11)
            keypress(0x56) 
            task.wait()
            keyrelease(0x56)
            keyrelease(0x11)
        end
        --
        Text = TextBox.Text
        --
        TextBox:Destroy()
        ScreenGui:Destroy()

        --
        return Text
    end
    --
    function utility:Position(xScale,xOffset,yScale,yOffset,instance)
        if instance then
            local x = instance.Position.x+xScale*instance.Size.x+xOffset
            local y = instance.Position.y+yScale*instance.Size.y+yOffset
            --
            return Vector2.new(x,y)
        else
            local vx,vy = ws.CurrentCamera.ViewportSize.x,ws.CurrentCamera.ViewportSize.y
            --
            local x = xScale*vx+xOffset
            local y = yScale*vy+yOffset
            --
            return Vector2.new(x,y)
        end
    end
    --
	function utility:Create(instanceType, instanceOffset, instanceProperties, instanceParent)
        local instanceType = instanceType or "Frame"
        local instanceOffset = instanceOffset or {Vector2.new(0,0)}
        local instanceProperties = instanceProperties or {}
        local instanceHidden = false
        local instance = nil
        --
		if instanceType == "Frame" or instanceType == "frame" then
            local frame = Drawing.new("Square")
            frame.Visible = true
            frame.Filled = true
            frame.Thickness = 0
            frame.Color = Color3.fromRGB(255,255,255)
            frame.Size = Vector2.new(100,100)
            frame.Position = Vector2.new(0,0)
            frame.ZIndex = 50
            frame.Transparency = library.shared.initialized and 1 or 0
            instance = frame
        elseif instanceType == "TextLabel" or instanceType == "textlabel" then
            local text = Drawing.new("Text")
            text.Font = 3
            text.Visible = true
            text.Outline = true
            text.Center = false
            text.Color = Color3.fromRGB(255,255,255)
            text.ZIndex = 50
            text.Transparency = library.shared.initialized and 1 or 0
            instance = text
        elseif instanceType == "Triangle" or instanceType == "triangle" then
            local frame = Drawing.new("Triangle")
            frame.Visible = true
            frame.Filled = true
            frame.Thickness = 0
            frame.Color = Color3.fromRGB(255,255,255)
            frame.ZIndex = 50
            frame.Transparency = library.shared.initialized and 1 or 0
            instance = frame
        elseif instanceType == "Image" or instanceType == "image" then
            local image = Drawing.new("Image")
            image.Size = Vector2.new(12,19)
            image.Position = Vector2.new(0,0)
            image.Visible = true
            image.ZIndex = 50
            image.Transparency = library.shared.initialized and 1 or 0
            instance = image
        elseif instanceType == "Circle" or instanceType == "circle" then
            local circle = Drawing.new("Circle")
            circle.Visible = false
            circle.Color = Color3.fromRGB(255, 0, 0)
            circle.Thickness = 1
            circle.NumSides = 30
            circle.Filled = true
            circle.Transparency = 1
            circle.ZIndex = 50
            circle.Radius = 50
            circle.Transparency = library.shared.initialized and 1 or 0
            instance = circle
        elseif instanceType == "Quad" or instanceType == "quad" then
            local quad = Drawing.new("Quad")
            quad.Visible = false
            quad.Color = Color3.fromRGB(255, 255, 255)
            quad.Thickness = 1.5
            quad.Transparency = 1 
            quad.ZIndex = 50
            quad.Filled = false
            quad.Transparency = library.shared.initialized and 1 or 0
            instance = quad
        elseif instanceType == "Line" or instanceType == "line" then
            local line = Drawing.new("Line")
            line.Visible = false
            line.Color = Color3.fromRGB(255, 255, 255)
            line.Thickness = 1.5
            line.Transparency = 1
            line.Thickness = 1.5
            line.ZIndex = 50
            line.Transparency = library.shared.initialized and 1 or 0
            instance = line
        end
        --
        if instance then
            for i, v in pairs(instanceProperties) do
                if i == "Hidden" or i == "hidden" then
                    instanceHidden = true
                else
                    if library.shared.initialized then
                        instance[i] = v
                    else
                        if instanceProperties.Hidden or instanceProperties.hidden then
                            instance[i] = v
                        else
                            if i ~= "Transparency" then
                                instance[i] = v
                            end
                        end
                    end
                end
            end
            --
            if not instanceHidden then
                library.drawings[#library.drawings + 1] = {instance, instanceOffset, instanceProperties["Transparency"] or 1}
            else
                library.hidden[#library.hidden + 1] = {instance}
            end
            --
            if instanceParent then
                instanceParent[#instanceParent + 1] = instance
            end
            --
            return instance
        end
	end
    --
    function utility:Instance(InstanceType, InstanceProperties)
        local Object = Instance.new(InstanceType)
        --
        for Index, Value in pairs(InstanceProperties) do
            Object[Index] = Value
        end
        --
        library.objects[Object] = true
        --
        return Object
    end
    --
    function utility:RemoveInstance(Object)
        library.objects[Object] = nil
        Object:Remove()
    end
    --
    function utility:UpdateOffset(instance, instanceOffset)
        for i,v in pairs(library.drawings) do
            if v[1] == instance then
                v[2] = instanceOffset
            end
        end
    end
    --
    function utility:UpdateTransparency(instance, instanceTransparency)
        for i,v in pairs(library.drawings) do
            if v[1] == instance then
                v[3] = instanceTransparency
            end
        end
    end
    --
    function utility:Remove(instance, hidden)
        library.colors[instance] = nil
        --
        local ind = 0
        --
        for i,v in pairs(hidden and library.hidden or library.drawings) do
            if v[1] == instance then
                ind = i
                if hidden then
                    v[1] = nil
                else
                    v[2] = nil
                    v[1] = nil
                end
            end
        end
        --
        Remove(hidden and library.hidden or library.drawings, ind)
        instance:Remove()
    end
    --
    function utility:GetSubPrefix(str)
        local str = tostring(str):gsub(" ","")
        local var = ""
        --
        if #str == 2 then
            local sec = string.sub(str,#str,#str+1)
            var = sec == "1" and "st" or sec == "2" and "nd" or sec == "3" and "rd" or "th"
        end
        --
        return var
    end
    --
    function utility:Connection(connectionType, connectionCallback)
        local connection = connectionType:Connect(connectionCallback)
        library.connections[#library.connections + 1] = connection
        --
        return connection
    end
    --
    function utility:Disconnect(connection)
        for i,v in pairs(library.connections) do
            if v == connection then
                library.connections[i] = nil
                v:Disconnect()
            end
        end
    end
    --
    function utility:MouseLocation()
        return uis:GetMouseLocation()
    end
    --
    function utility:MouseOverDrawing(values, valuesAdd)
        local valuesAdd = valuesAdd or {}
        local values = {
            (values[1] or 0) + (valuesAdd[1] or 0),
            (values[2] or 0) + (valuesAdd[2] or 0),
            (values[3] or 0) + (valuesAdd[3] or 0),
            (values[4] or 0) + (valuesAdd[4] or 0)
        }
        --
        local mouseLocation = utility:MouseLocation()
	    return (mouseLocation.x >= values[1] and mouseLocation.x <= (values[1] + (values[3] - values[1]))) and (mouseLocation.y >= values[2] and mouseLocation.y <= (values[2] + (values[4] - values[2])))
    end
    --
    function utility:GetTextBounds(text, textSize, font)
        local textbounds = Vector2.new(0, 0)
        --
        local textlabel = utility:Create("TextLabel", {Vector2.new(0, 0)}, {
            Text = text,
            Size = textSize,
            Font = font,
            Hidden = true
        })
        --
        textbounds = textlabel.TextBounds
        utility:Remove(textlabel, true)
        --
        return textbounds
    end
    --
    function utility:GetScreenSize()
        return ws.CurrentCamera.ViewportSize
    end
    --
    function utility:LoadImage(instance, imageName, imageLink)
        local data
        --
        if isfile(library.folders.assets.."/"..imageName..".png") then
            data = readfile(library.folders.assets.."/"..imageName..".png")
        else
            if imageLink then
                data = game:HttpGet(imageLink)
                writefile(library.folders.assets.."/"..imageName..".png", data)
            else
                return
            end
        end
        --
        if data and instance then
            instance.Data = data
        end
    end
    --
    function utility:Lerp(instance, instanceTo, instanceTime)
        local currentTime = 0
        local currentIndex = {}
        local connection
        --
        for i,v in pairs(instanceTo) do
            currentIndex[i] = instance[i]
        end
        --
        local function lerp()
            for i,v in pairs(instanceTo) do
                instance[i] = ((v - currentIndex[i]) * currentTime / instanceTime) + currentIndex[i]
            end
        end
        --
        connection = utility:Connection(rs.RenderStepped, function(delta)
            if currentTime < instanceTime then
                currentTime = currentTime + delta
                lerp()
            else
                connection:Disconnect()
            end
        end)
        --
        
    end
    --
    function utility:Combine(table1, table2)
        local table3 = {}
        for i,v in pairs(table1) do table3[i] = v end
        local t = #table3
        for z,x in pairs(table2) do table3[z + t] = x end
        return table3
    end
    --
    function utility:WrapText(Text, Size)
        local Max = (Size / 7)
        --
        return Text:sub(0, Max)
    end
    --
    function utility:InputToString(Input)
        if Input then
            local String = (tostring(Input) .. "."):gsub("%.", ",")
            local Count = 0
            --
            for Value in String:gmatch("(.-),") do
                Count = Count + 1
                --
                if Count == 3 then
                    String = Value:gsub("Keypad", "")
                end
            end
            --
            if String == "Unknown" or Input.Value == 27 then
                return "None"
            elseif utility.Keyboard.InputNames[String] then
                String = utility.Keyboard.InputNames[String]
            end
            --
            return String
        else
            return "None"
        end
    end
end

-- // Library Functions
do
    library.__index = library
	pages.__index = pages
	sections.__index = sections
    --
    function library:Notification(info)
    end
    --
    function library:Loader(info)
		local info = info or {}
        local name = info.name or info.Name or info.title or info.Title or "UI Title"
        local size = info.size or info.Size or Vector2.new(375,359)
        local accent = info.accent or info.Accent or info.color or info.Color or theme.accent
        local callback = info.callback or info.Callback or info.callBack or info.CallBack or function() end
        local pageammount = info.pages or info.Pages or 1
        --
        theme.accent = accent
        --
        local window = {pages = {}, loader = true, isVisible = false, pageammount = pageammount, callback = callback, wminfo = "$$$$$ AntarcticaWare $$$$$ || UID : %u || Ping : %s || Fps : %u", currentPage = nil, fading = false, dragging = false, drag = Vector2.new(0,0), currentContent = {frame = nil, dropdown = nil, multibox = nil, colorpicker = nil, keybind = nil, textbox = nil}}
        --
        local main_frame = utility:Create("Frame", {Vector2.new(0,0)}, {
            Size = utility:Size(0, size.X, 0, size.Y),
            Position = utility:Position(0.5, -(size.X/2) ,0.5, -(size.Y/2)),
            Color = theme.outline
        });window["main_frame"] = main_frame
        --
        library.colors[main_frame] = {
            Color = "outline"
        }
        --
        local frame_inline = utility:Create("Frame", {Vector2.new(1,1), main_frame}, {
            Size = utility:Size(1, -2, 1, -2, main_frame),
            Position = utility:Position(0,
